from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Firefox()

driver.get("http://nitrowriters.com/form/form.html")

txt = driver.find_element(By.ID, "my_text_field")
txt.send_keys("hola")

descriptions = driver.find_elements(By.CLASS_NAME, "description")

for desc in descriptions:
    print(desc)

text_area = driver.find_element(By.TAG_NAME, "textarea")
text_area.send_keys("wololo")

link = driver.find_element(By.LINK_TEXT, "Go to SitePoint")
print(link.text)
#link.click()

inputs = driver.find_elements(By.TAG_NAME, "input")
for inpt in inputs:
    if inpt.get_attribute("type") == "text":
        inpt.clear()
        inpt.send_keys("WOOP WOOP")

#options = driver.find_elements(By.CSS_SELECTOR, "* option")
#for option in options:
    #print(option.text)


# Universal
print(" = = = = = = = = Universal = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "*")
for element in elements:
    print(element.text)

# Grouping type selector
print(" = = = = = = = = Grouping type selector = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "h1, h2, h3, h4, h5, h6")
for element in elements:
    print(element.text)

# Descendant selector
print(" = = = = = = = = Descendant selector = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "form input")
for element in elements:
    print(element.text)

# Child selector
print(" = = = = = = = = Child selector = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "form > input")
for element in elements:
    print(element.text)

# Adjacent sibling
print(" = = = = = = = = Adjacent sibling = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "input + input")
for element in elements:
    print(element.text)

# General sibling
print(" = = = = = = = = General sibling = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "p ~ p")
for element in elements:
    print(element.text)

# Class selector
print(" = = = = = = = = Class selector = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, ".form_description")
for element in elements:
    print(element.text)

# Id selector
print(" = = = = = = = = Id selector = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "#my_description")
for element in elements:
    print(element.text)

# Pseudo element
print(" = = = = = = = = Pseudo element = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "p::first-line")
for element in elements:
    print(element.text)

# Pseudo class selector
print(" = = = = = = = = Pseudo class selector = = = = = = = = ")
elements = driver.find_elements(By.CSS_SELECTOR, "a:link")
for element in elements:
    print(element.text)
