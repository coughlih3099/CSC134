# CSC 134
# M2Lab2 - Turtle
# Harley Coughlin
# 09/04/2024

from turtle import Turtle, Screen
from random import randint


def draw_body(turtle: Turtle, distance: int) -> None:
    body_length =  int(distance / 10)
    for i in range(body_length):
        if turtle.pensize() < 2:
            turtle.pensize(4)
        if i < 1 or i > body_length - 2:
            turtle.pensize(5)
        elif i&1 == 0:
            turtle.pensize(turtle.pensize() - randint(1, 2) + randint(1, 2))
        else:
            turtle.pensize(turtle.pensize() + randint(1, 2) - randint(1, 2))
        turtle.fd(10)

def main():
    s = Screen()
    t = Turtle()
    t.speed(0)
    s.colormode(255)
    t.ht()

    body_width = 160
    body_length = 200
    t.fillcolor((207, 209, 210))
    t.pensize(5)

    # draw the body
    t.begin_fill()
    for i in range(4):
        if i & 1 == 0:
            draw_body(t, body_width)
        else:
            draw_body(t, body_length)
        t.left(90)
    t.end_fill()

    # right arm
    arm_length = 90
    t.pensize(4)
    t.pu()
    t.seth(90)
    t.fd(body_length / 3)
    t.seth(180)
    t.pd()
    t.fd(arm_length - 20)
    t.pu()
    t.fd(20)
    t.pd()
    t.seth(150)
    t.begin_fill()
    t.circle(5, 290, steps=10)
    t.seth(250)
    t.circle(5, 270, steps=10)
    t.seth(250)
    t.circle(5, 290)
    t.end_fill()
    t.fd(13)

    # left arm
    t.seth(0)
    t.pu()
    t.fd(250)
    t.pd()
    t.fd(arm_length)
    t.seth(10)
    t.begin_fill()
    t.fd(30)
    t.circle(-5, 200)
    t.seth(190)
    t.fd(13)
    t.seth(315)
    t.fd(12)
    t.circle(-4, 200)
    t.seth(135)
    t.fd(12)
    t.seth(280)
    t.fd(10)
    t.circle(-3, 230)
    t.seth(110)
    t.fd(19)
    t.end_fill()

    # pants and tie
    t.teleport(0, 0)
    t.pu()
    t.seth(90)
    t.fd(body_length / 4)
    t.pd()
    t.seth(0)
    t.fd(body_width)
    t.pu()
    t.seth(180)
    t.fd(75)
    t.pd()
    t.seth(235)
    t.fd(35)
    t.seth(305)
    t.fd(18)
    t.seth(55)
    t.fd(18)
    t.seth(125)
    t.fd(35)

    # legs
    leg_length = 60
    foot_length = 15
    t.teleport(0, 0)
    t.seth(0)
    t.pu()
    t.fd(body_width * 0.2)
    t.seth(270)
    t.pd()
    t.fd(leg_length)
    t.seth(180)
    t.fd(foot_length)
    t.teleport(160, 0)
    t.pu()
    t.fd(body_width * 0.2)
    t.seth(270)
    t.pd()
    t.fd(leg_length)
    t.seth(180)
    t.fd(foot_length)

    # eyes, nose, mouth
    t.seth(0)
    # left eye
    t.teleport(body_width * 0.25, body_length * 0.6)
    t.circle(19)
    # left iris
    t.teleport(body_width * 0.28, body_length * 0.63)
    t.circle(3)
    # left eyelashes #
    t.seth(90)
    t.teleport(body_width * 0.23, body_length * 0.8)
    t.fd(12)
    t.teleport(body_width * 0.18, body_length * 0.77)
    t.fd(10)
    t.teleport(body_width * 0.13, body_length * 0.73)
    t.fd(8)
    #################
    # right eye
    t.seth(0)
    t.teleport(body_width * 0.7, body_length * 0.53)
    t.circle(31)
    # right iris
    t.teleport(body_width * 0.62, body_length * 0.58)
    t.circle(6)
    # right eyelashes #
    t.seth(90)
    t.teleport(body_width * 0.7, body_length * 0.85)
    t.fd(12)
    t.teleport(body_width * 0.63, body_length * 0.83)
    t.seth(100)
    t.fd(10)
    t.teleport(body_width * 0.76, body_length * 0.83)
    t.seth(85)
    t.fd(10)
    ###################
    t.seth(0)
    # nose
    t.teleport(body_width * 0.43, body_length * 0.53)
    t.circle(8)
    # mouth
    t.teleport(body_width * 0.15, body_length * 0.45)
    t.fd(body_width * 0.63)
    # left tooth
    t.teleport(body_width * 0.23, body_length * .45)
    t.seth(270)
    t.fd(15)
    t.seth(0)
    t.fd(25)
    t.seth(90)
    t.fd(15)
    # right tooth
    t.teleport(body_width * 0.53, body_length * .45)
    t.seth(270)
    t.fd(15)
    t.seth(0)
    t.fd(25)
    t.seth(90)
    t.fd(15)

    # spots
    t.color((75, 124, 114))
    t.shape("circle")
    t.shapesize(.2, .2)
    t.teleport(body_width * 0.5, body_length * 0.9)
    t.stamp()
    t.teleport(body_width * 0.43, body_length * 0.8)
    t.stamp()
    t.teleport(body_width * 0.1, body_length * 0.5)
    t.stamp()
    t.teleport(body_width * 0.1, body_length * 0.4)
    t.stamp()
    t.teleport(body_width * 0.1, body_length * 0.2)
    t.stamp()
    t.teleport(body_width * 0.9, body_length * 0.4)
    t.stamp()
    t.teleport(body_width * 0.8, body_length * 0.36)
    t.stamp()
    t.teleport(body_width * 0.8, body_length * 0.12)
    t.stamp()
    t.teleport(body_width * 0.7, body_length * 0.1)
    t.stamp()

    s.exitonclick()


if __name__ == "__main__":
    main()
