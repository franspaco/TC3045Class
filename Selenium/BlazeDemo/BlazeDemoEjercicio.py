
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

from getEmails import *
from reservarVuelos import *

driver = webdriver.Firefox()

emails = getEmails(driver)


source = "http://blazedemo.com/register"

# "You are logged in!"


for email, name in emails.items():
    driver.get(source)
    txt = driver.find_element(By.ID, "name")
    txt.send_keys(name)

    txt = driver.find_element(By.ID, "company")
    txt.send_keys("ITESM")

    txt = driver.find_element(By.ID, "email")
    em = randomCard(10) + email[2:]
    txt.send_keys(em)

    txt = driver.find_element(By.ID, "password")
    txt.send_keys("123456")

    txt = driver.find_element(By.ID, "password-confirm")
    txt.send_keys("123456")

    driver.find_element(By.CSS_SELECTOR, "form.form-horizontal").submit()

    try:
        element = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, "li.dropdown"))
        )
        print("REGISTRADO: " + em)
    except:
        print("FAILED TO REGISTER")
        continue

    reservarVuelos(driver, name, email)
    driver.get(source)
    driver.find_element(By.CSS_SELECTOR, "a.dropdown-toggle").click()

    driver.find_element(By.CSS_SELECTOR, "a[href=\"http://blazedemo.com/logout\"]").click()


driver.quit()
