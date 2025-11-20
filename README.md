Sistema de Gestión para Cibercafé

Proyecto desarrollado en C que simula un sistema de administración típico de un ciber, con manejo de usuarios, administrador, sesiones y herramientas internas.

Características principales

Sistema de login:

- Inicio de sesión como usuario o administrador.

- Validación mediante nombre y contraseña.

Gestión de cuentas:

- Crear nuevas cuentas de usuario.

- Ver usuarios registrados.

Menú del Usuario:

- Ver precios del servicio.

- Acceso a calculadora integrada.

- Consulta de datos básicos.

Menú del Administrador:

- Ver todas las cuentas creadas.

- Acceso completo a funciones internas.

Funciones auxiliares:

- Búsqueda de cuentas por nombre.

- Simulación parcial de historial y tiempo restante (pendiente de completar).

- Estructura del proyecto

- Uso de struct para almacenar usuarios (nombre + contraseña).

- Arrays para gestión de múltiples cuentas.

- Validación básica de credenciales.

- Menús interactivos independientes para user/admin.

Organización modular en funciones:
- menuAdmin, menuUsuario, buscarCuentaUsuario, CrCuUsuario, etc.

Objetivo

Simular un sistema real de administración con roles, autenticación y herramientas comunes, aplicando modularidad, validación e interacción por consola.
