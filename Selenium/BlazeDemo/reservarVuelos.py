import random
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import Select

def randomCard(length):
    out = ""
    for num in range(0,length):
        out += str(random.randint(0,9))
    return out

def reservarVuelos(driver, name, email):
    driver.get('http://blazedemo.com/')
    fromList = Select(driver.find_element(By.NAME, "fromPort"))
    toList = Select(driver.find_element(By.NAME, "toPort"))

    fromList.select_by_index(random.randint(0,6))
    toList.select_by_index(random.randint(0,6))

    driver.find_element(By.CSS_SELECTOR, "input[value=\"Find Flights\"]").click()

    flights = driver.find_elements(By.CSS_SELECTOR, "input[value=\"Choose This Flight\"]")

    flights[random.randint(0, len(flights)-1)].click()

    driver.find_element_by_name("inputName").send_keys(name)
    driver.find_element_by_name("address").send_keys(name)
    driver.find_element_by_name("city").send_keys("CDMX")
    driver.find_element_by_name("state").send_keys("CDMX")
    driver.find_element_by_name("zipCode").send_keys(randomCard(5))
    
    Select(driver.find_element_by_name("cardType")).select_by_index(random.randint(0,2))

    driver.find_element_by_name("creditCardNumber").send_keys(randomCard(16))

    temp = driver.find_element_by_name("creditCardMonth")
    temp.clear()
    temp.send_keys(str(random.randint(1, 12)))

    temp = driver.find_element_by_name("creditCardYear")
    temp.clear()
    temp.send_keys(str(random.randint(2018, 2025)))

    driver.find_element_by_name("nameOnCard").send_keys(name)

    driver.find_element(By.CSS_SELECTOR, "input[value=\"Purchase Flight\"]").click()



if __name__ == '__main__':
    driver = webdriver.Firefox()
    email = "wololoolol@dsvf.dsf"
    name = "dsvdsfvdfvf"
    reservarVuelos(driver, name, email)
