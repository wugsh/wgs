from flask import Flask
from application.settings.dev import DevelopementConfig
from application.settings.prop import ProductionConfig

config = {
    "dev": DevelopementConfig,
    "prop": ProductionConfig
}
def ini_app(config_name):
    app = Flask(__name__)
