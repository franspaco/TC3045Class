from selenium import webdriver
from selenium.webdriver.common.by import By

def getEmails(driver):

    #driver = webdriver.Firefox()

    source = "http://micampus.csf.itesm.mx/index.php/division-de-diseno-ingenieria-y-arquitectura/directorio"

    driver.get(source)

    names = []
    emails = []

    elements = driver.find_elements(By.TAG_NAME, "td")
    for indx, element in enumerate(elements):
        if indx % 4 == 0:
            name = element.text.split("\n")[0]
            names.append(name)
        elif indx % 4 == 3:
            emails.append(element.text)

    data = {}

    for index in range(len(names)):
        data[emails[index]] = names[index]
        print(str(names[index]) + " - " + str(emails[index]))
    return data

if __name__ == '__main__':
    driver = webdriver.Firefox()
    getEmails(driver)