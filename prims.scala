
final class Graph(numVertices: Int, start: Int = 0) {
 
  class Vertex(val id: Int, 
     var load: Int = Int.MaxValue, 
     var tree: Int = -1) 

  val vertices = List.tabulate(numVertices)(new Vertex(_))
  vertices.head.load = 0
  val edges = new HashMap[Vertex, HashMap[Vertex, Int]]

  def += (from: Int, to: Int, weight: Int): Unit = {
    val fromV = vertices(from)
    val toV = vertices(to)
    connect(fromV, toV, weight)
    connect(toV, fromV, weight)
  }
  def connect(from: Vertex, to: Vertex, weight: Int): Unit = {
    if( !edges.contains(from))
      edges.put(from, new HashMap[Vertex, Int])    
    edges.get(from).get.put(to, weight)
  }   
  // ...
}
