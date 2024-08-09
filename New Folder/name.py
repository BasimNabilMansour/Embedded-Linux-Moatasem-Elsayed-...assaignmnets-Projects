#!/usr/bin/python3
# -*- coding: utf-8 -*-
import pyglet
import arabic_reshaper
import bidi.algorithm

window =pyglet.window.Window()
reshaped_text=arabic_reshaper.reshape("بسم الله الرحمن الرحيم")
bidi_text=bidi.algorithm.get_display(reshaped_text)

label=pyglet.text.Label(bidi_text,font_name="arial",font_size=36,x=window.width//2,y=window.height//2,anchor_x='center',anchor_y='center')

@window.event

def on_draw():
    window.clear()
    label.draw()
    
pyglet.app.run()    