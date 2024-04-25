import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import automation
from esphome.components import sensor
from esphome.const import (
    CONF_ID,
    CONF_LAMBDA,
    CONF_STATE,
)

mynamespace_ns = cg.esphome_ns.namespace("mynamespace_")

MyNamespaceSensor = mynamespace_ns.class_(
    "MyNamespaceSensor", sensor.Sensor, cg.PollingComponent
)

CONFIG_SCHEMA = (
    sensor.sensor_schema(
        MyNamespaceSensor,
        accuracy_decimals=1,
    )
    .extend(
        {
            cv.Optional(CONF_LAMBDA): cv.returning_lambda,
        }
    )
    .extend(cv.polling_component_schema("60s"))
)


async def to_code(config):
    var = await sensor.new_sensor(config)
    await cg.register_component(var, config)

    if CONF_LAMBDA in config:
        mynamespace_ = await cg.process_lambda(
            config[CONF_LAMBDA], [], return_type=cg.optional.mynamespace(float)
        )
        cg.add(var.set_mynamespace(mynamespace_))


@automation.register_action(
    "sensor.mynamespace.publish",
    sensor.SensorPublishAction,
    cv.Schema(
        {
            cv.Required(CONF_ID): cv.use_id(sensor.Sensor),
            cv.Required(CONF_STATE): cv.templatable(cv.float_),
        }
    ),
)
async def sensor_mynamespace_publish_to_code(config, action_id, mynamespace_arg, args):
    paren = await cg.get_variable(config[CONF_ID])
    var = cg.new_Pvariable(action_id, mynamespace_arg, paren)
    mynamespace_ = await cg.templatable(config[CONF_STATE], args, float)
    cg.add(var.set_state(mynamespace_))
    return var
