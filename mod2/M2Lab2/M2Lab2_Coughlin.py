from turtle import Turtle


def swim(x, y):
    tclone = t.clone()
    tclone.goto(x, y)
    while True:
        n, e = xy = tclone.pos()
        if n == x and e == y:
            tclone.ht()
            tclone.clear()
            break

t = Turtle()
screen = t.screen
screen.setup(width=0.8, height=0.8, startx=None, starty=None)
screen.title("Turtle Command")
screen.bgpic("background.png")
t.ht()
t.shape("turtle")
t.shapesize(stretch_wid=1.6, stretch_len=1.6)
t.setheading(90)
t.teleport(0, -410)
t.st()

xy = screen.onclick(swim)

screen.mainloop()
