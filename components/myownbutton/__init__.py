from esphome.components import button
import esphome.codegen as cg

mybutton_ns = cg.esphome_ns.namespace("mybuttonns")

MyOwnButton = mybutton_ns.class_("MyOwnButton", button.Button)

CONFIG_SCHEMA = button.button_schema(MyOwnButton)


async def to_code(config):
    await button.new_button(config)
