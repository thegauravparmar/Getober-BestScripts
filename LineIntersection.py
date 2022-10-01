from array import array
import pygame
import numpy as np
screenWidth = 1200
screenHeight = 800

screen = pygame.display.set_mode((screenWidth, screenHeight))
pygame.display.set_caption("Rectangle")


points = []


def draw():
    screen.fill("black")



def lineIntersectionOnRect(width, height, xB, yB, xA, yA):
    w = width / 2
    h = height / 2

    dx = xA - xB
    dy = yA - yB

    coord = {}

    if (dx == 0 and dy == 0):
        coord['x'] = xB
        coord['y'] = yB
        return coord

    tan_phi = h / w
    tan_theta = abs(dy / dx)

    qx = np.sign(dx)
    qy = np.sign(dy)

    if (tan_theta > tan_phi):
        xI = xB + (h / tan_theta) * qx
        yI = yB + h * qy
        coord['x'] = xI
        coord['y'] = yI
        return coord
    else:
        xI = xB + w * qx
        yI = yB + w * tan_theta * qy
        coord['x'] = xI
        coord['y'] = yI
        return coord



def grid():
    points=[(120, 200), (121, 200), (122, 200), (123, 200), (124, 200), (125, 200), (126, 200), (127, 200), (128, 200), (129, 200), (130, 200), (131, 200), (132, 200), (133, 200), (134, 200), (135, 200), (136, 200), (137, 200), (138, 200), (139, 200), (140, 200), (141, 200), (142, 200), (143, 200), (144, 200), (145, 200), (146, 200), (147, 200), (148, 200), (149, 200), (150, 200), (151, 200), (152, 200), (153, 200), (154, 200), (155, 200), (156, 200), (157, 200), (158, 200), (159, 200), (160, 200), (161, 200), (162, 200), (163, 200), (164, 200), (165, 200), (166, 200), (167, 200), (168, 200), (169, 200), (170, 200), (171, 200), (172, 200), (173, 200), (174, 200), (175, 200), (176, 200), (177, 200), (178, 200), (179, 200), (180, 200), (181, 200), (182, 200), (183, 200), (184, 200), (185, 200), (186, 200), (187, 200), (188, 200), (189, 200), (190, 200), (191, 200), (192, 200), (193, 200), (194, 200), (195, 200), (196, 200), (197, 200), (198, 200), (199, 200), (200, 200), (201, 200), (202, 200), (203, 200), (204, 200), (205, 200), (206, 200), (207, 200), (208, 200), (209, 200), (210, 200), (211, 200), (212, 200), (213, 200), (214, 200), (215, 200), (216, 200), (217, 200), (218, 200), (219, 200)]
    pygame.display.update()
    pygame.draw.polygon(screen,'pink',points)
    pygame.display.update()

def update_rect(self):
    rect = pygame.Rect(0, 0, 0, 0)
    for k in self.objects:
        o = self.objects[k]
        rect = rect.union(o.rect)
        
    self.rect.w = rect.w + self.canvas.style["d_space"] * 2
    self.rect.h = rect.h + self.canvas.style["d_space"] * 2
    self.offset_x = self.canvas.style["d_space"]
    self.offset_y = self.canvas.style["d_space"]
    
    if len(self.inputs) > 1:
        self.rect.w += self.parent.canvas.style["d_input"]
        self.offset_x += self.parent.canvas.style["d_input"]
    if len(self.outputs) > 1:
        self.rect.w += self.parent.canvas.style["d_output"]
    self.rect_rel = Rect(self.rect)
    self.rect_rel.x = 0
    self.rect_rel.y = 0
    self.update_io_xy()

def callExit(localPoint: array):

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
    

    pygame.display.update()


draw()

grid()

while (1):
    callExit(points)
