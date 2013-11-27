<?php
/**
 * @file
 * featurerule.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function featurerule_default_rules_configuration() {
  $items = array();
  $items['rules_ejerciciorule'] = entity_import('rules_config', '{ "rules_ejerciciorule" : {
      "LABEL" : "EjercicioRuleAdministrador",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_update--contenidorules" : { "bundle" : "contenidorules" },
        "node_insert--contenidorules" : { "bundle" : "contenidorules" }
      },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "Contenido editado",
            "message" : "Se ha editado o a\\u00f1adido contenido de tipo ContenidoRule"
          }
        }
      ]
    }
  }');
  $items['rules_ejercicioruleestado'] = entity_import('rules_config', '{ "rules_ejercicioruleestado" : {
      "LABEL" : "EjercicioRuleEstado",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_update--contenidorules" : { "bundle" : "contenidorules" },
        "node_insert--contenidorules" : { "bundle" : "contenidorules" }
      },
      "IF" : [ { "data_is" : { "data" : [ "node:field-estado" ], "value" : "2" } } ],
      "DO" : [ { "node_unpublish" : { "node" : [ "node" ] } } ]
    }
  }');
  return $items;
}
