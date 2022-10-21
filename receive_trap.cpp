char receivetrap_cpp_version[]="@(#) SNMP++ $Id: receive_trap.cpp 2359 2013-05-09 20:07:01Z fock $";
#include <libsnmp.h>

#include "snmp_pp/snmp_pp.h"
#include "snmp_pp/collect.h"
#include "snmp_pp/notifyqueue.h"

#ifdef SNMP_PP_NAMESPACE
using namespace Snmp_pp;
#endif

void callback( int reason, Snmp *snmp, Pdu &pdu, SnmpTarget &target, void *cd)
{
  Vb nextVb;
  int pdu_error;
  GenAddress addr;

  target.get_address(addr);
  UdpAddress from(addr);

  cout << "reason: " << reason << endl
       << "msg: " << snmp->error_msg(reason) << endl
       << "from: " << from.get_printable() << endl;

  pdu_error = pdu.get_error_status();
  if (pdu_error){
    cout << "Response contains error: " 
	 << snmp->error_msg(pdu_error)<< endl;
  }
  Oid id;
  pdu.get_notify_id(id);
  cout << "ID:  " << id.get_printable() << endl;
  cout << "Type:" << pdu.get_type() << endl;

  for (int i=0; i<pdu.get_vb_count(); i++)
  {
    pdu.get_vb(nextVb, i);

    cout << "Oid: " << nextVb.get_printable_oid() << endl
	 << "Val: " <<  nextVb.get_printable_value() << endl;
  }
  if (pdu.get_type() == sNMP_PDU_INFORM) {
      cout << "pdu type: " << pdu.get_type() << endl;
      cout << "sending response to inform: " << endl;
      nextVb.set_value("This is the response.");
      pdu.set_vb(nextVb, 0);
      snmp->response(pdu, target);
  }
  cout << endl;
}

int main(int argc, char **argv)
{
  int trap_port;
  if (argc < 2)
    trap_port = 10162; // no need to be root
  else
    trap_port = atoi(argv[1]);

  //----------[ create a SNMP++ session ]-----------------------------------
  int status; 
  Snmp::socket_startup();  // Initialize socket subsystem
  Snmp snmp(status);                // check construction status
  if ( status != SNMP_CLASS_SUCCESS)
  {
    cout << "SNMP++ Session Create Fail, " << snmp.error_msg(status) << "\n";
    return 1;
  }

   //---------[ init SnmpV3 ]--------------------------------------------
#ifdef _SNMPv3
   const unsigned char engineId[] = 
       { 0x80, 0x00, 0x13, 0x70, 0xC0, 0xA8, 0x01, 0x0D };
   OctetStr engineID(engineId, 8);
   const char *filename = "snmpv3_boot_counter";
   unsigned int snmpEngineBoots = 0;
   v3MP *v3_MP;

   status = getBootCounter(filename, engineID, snmpEngineBoots);
   if ((status != SNMPv3_OK) && (status < SNMPv3_FILEOPEN_ERROR))
   {
     cout << "Error loading snmpEngineBoots counter: " << status << endl;
     return 1;
   }
   snmpEngineBoots++;
   status = saveBootCounter(filename, engineID, snmpEngineBoots);
   if (status != SNMPv3_OK)
   {
     cout << "Error saving snmpEngineBoots counter: " << status << endl;
     return 1;
   }

   int construct_status;
   v3_MP = new v3MP(engineID, snmpEngineBoots, construct_status);
   if (construct_status != SNMPv3_MP_OK)
   {
     cout << "Error initializing v3MP: " << construct_status << endl;
     return 1;
   }

   USM *usm = v3_MP->get_usm();

   // users at UCD
   usm->add_usm_user("SHADESUser",
		     SNMP_AUTHPROTOCOL_HMACSHA, SNMP_PRIVPROTOCOL_DES,
		     "The UCD Demo Password", "The UCD Demo Password");

  usm->add_usm_user("SHAMD5User",
		    SNMP_AUTHPROTOCOL_HMACMD5, SNMP_PRIVPROTOCOL_DES,
		    "The UCD Demo Password", "The UCD Demo Password");

  usm->add_usm_user("noAuthUser",
		    SNMP_AUTHPROTOCOL_HMACMD5, SNMP_PRIVPROTOCOL_DES,
		    "Password", "Password");

  // testusers
  usm->add_usm_user("unsecureUser",
		    SNMP_AUTHPROTOCOL_NONE, SNMP_PRIVPROTOCOL_NONE, 
		    "", "");

  usm->add_usm_user("MD5",
		    SNMP_AUTHPROTOCOL_HMACMD5, SNMP_PRIVPROTOCOL_NONE,
		    "MD5UserAuthPassword", "");

  usm->add_usm_user("SHA",
		    SNMP_AUTHPROTOCOL_HMACSHA, SNMP_PRIVPROTOCOL_NONE,
		    "SHAUserAuthPassword", "");

  usm->add_usm_user("MD5DES",
		    SNMP_AUTHPROTOCOL_HMACMD5, SNMP_PRIVPROTOCOL_DES,
		    "MD5DESUserAuthPassword", "MD5DESUserPrivPassword");

  usm->add_usm_user("SHADES",
		    SNMP_AUTHPROTOCOL_HMACSHA, SNMP_PRIVPROTOCOL_DES,
		    "SHADESUserAuthPassword", "SHADESUserPrivPassword");

  usm->add_usm_user("MD5IDEA",
		    SNMP_AUTHPROTOCOL_HMACMD5, SNMP_PRIVPROTOCOL_IDEA,
		    "MD5IDEAUserAuthPassword", "MD5IDEAUserPrivPassword");

  usm->add_usm_user("SHAIDEA",
		    SNMP_AUTHPROTOCOL_HMACSHA, SNMP_PRIVPROTOCOL_IDEA,
		    "SHAIDEAUserAuthPassword", "SHAIDEAUserPrivPassword");

#endif
   OidCollection oidc;
   TargetCollection targetc;

   cout << "Trying to register for traps on port " << trap_port << "." << endl;
   snmp.notify_set_listen_port(trap_port);
   status = snmp.notify_register(oidc, targetc, callback, NULL);
   if (status != SNMP_CLASS_SUCCESS)
   {
     cout << "Error register for notify (" << status << "): "
	  << snmp.error_msg(status) << endl;
     exit(1);
   }
   else
     cout << "Waiting for traps/informs..." << endl;


  snmp.start_poll_thread(1000);

  cout << "press return to stop\n";
  getc(stdin);

  snmp.stop_poll_thread();

  Snmp::socket_cleanup();  // Shut down socket subsystem
}
