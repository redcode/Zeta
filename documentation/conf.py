# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

author = u'Manuel Sainz de Baranda y Goñi'
copyright = u'2006-2024 Manuel Sainz de Baranda y Goñi'
extensions = ['breathe']
templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']
breathe_domain_by_extension = {'h': 'c'}
html_static_path = ['_static']
latex_elements = {'releasename': 'Version'}
