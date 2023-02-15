import sys
from lxml import etree

print("Hello World!")

tree = etree.parse("fichier.xml") # Manipuler l'arbre du fichier.xml

root = tree.getroot() # trouver la racine

etree.dump(root) # Contenu xml de la racine

children = root.getchildren() # Tous les Elements enfants

fruits = tree.xpath("produit/fruit") # Les elements fruit
legumes = tree.xpath("//legume") # Les elements legume

fruits[0] # Premier fruit
fruits.attrib['type'] # Valeur de l'attribut 'type' de fruit

fruit_attribut = tree.xpath("produit/fruit[1]/@type") # Valeur de l'attribut 'type' du 2eme fruit

fruit_attribut = tree.xpath("produit/fruit/@type") # Valeur de l'attribut 'type' de chaque fruit

fruits[0].get('type') # Recuperer l'attribut 'type' du premier fruit

sum(int(p) for p in tree.xpath("//fruit/@prix")) # Calcule la somme du prix de chaque fruit (transforme la liste de texte en int pour calculer chaque attribut).

fruits[0].set('prix', 210) # Changer la valeur de l'attribut 'prix' avec la valeur 210 pour le 1er fruit

tree.write("Doc.xml", pretty_print=True, xml_declaration=True, encoding="UTF-8")