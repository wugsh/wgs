#!/usr/bin/env python
# coding=utf-8
 
try:
    from setuptools import setup

except ImportError:
    from distutils.core import setup

config = {
    'description': 'My Project',
    'author': 'GaoSHeng Wu',
    'url': '.......',
    'download_url': '......',
    'author_email' : 'My email.',
    'version': '0.1',
    'install_requires': ['nose'],
    'packages': ['NAME'],
    'scripts': [],
    'name': 'projectname'
}

setup(**config)
