#!/usr/bin/env python
# coding=utf-8

from nose.tools import :
from ex47.game import Room

def test_room():
    gold = Room("GoldRoom", """ The room has gold in it you  can grap. There's a door to the north.""")
    assert_equal(gold.name, "GoldRoom")

