import random
import string
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import Select

def rand_str(n):
    letters = string.ascii_lowercase
    out = ""
    for num in range(0, n):
        out += letters[random.randint(0,25)]
    return out

def randomCard(length):
    out = ""
    for num in range(0,length):
        out += str(random.randint(0,9))
    return out

def addProds(driver):
    import urllib
    txt = str(urllib.request.urlopen('https://franspaco.com/lorem.txt').read())

    driver.get("http://localhost/admin")

    # LOGIN
    driver.find_element(By.NAME, "username").send_keys('admin')
    driver.find_element(By.NAME, "password").send_keys('12345')

    driver.find_element(By.CSS_SELECTOR, "button.btn-primary").click()


    # MENU DE PRODUCTOS
    driver.find_element(By.XPATH, '//*[@id="menu-catalog"]/a').click()
    driver.find_element(By.XPATH, '//*[@id="collapse1"]/li[2]/a').click()


    # PRODUCTO 1
    driver.find_element(By.XPATH, '//*[@id="collapse1-1"]/li[1]/a').click()
    driver.find_element(By.XPATH, '//*[@id="content"]/div[1]/div/div/a').click()

    driver.find_element(By.XPATH, '//*[@id="input-name1"]').send_keys('SUPER WOW PRODUCTO-MATIC 10,000')
    driver.find_element(By.XPATH, '//*[@id="input-meta-title1"]').send_keys('PRODUCTOOO')
    cmd = 'document.querySelector("#language1 > div:nth-child(2) > div > div > div.note-editing-area > div.note-editable.panel-body > p").innerHTML = "' + txt + '";'
    driver.execute_script(cmd)
    driver.find_element(By.XPATH, '//*[@id="form-product"]/ul/li[2]/a').click()
    driver.find_element(By.XPATH, '//*[@id="input-model"]').send_keys("SUPER")
    driver.find_element(By.XPATH, '//*[@id="input-price"]').send_keys("100")
    driver.find_element(By.XPATH, '//*[@id="content"]/div[1]/div/div/button').click()


    # PRODUCTO 2
    driver.find_element(By.XPATH, '//*[@id="collapse1-1"]/li[1]/a').click()
    driver.find_element(By.XPATH, '//*[@id="content"]/div[1]/div/div/a').click()

    driver.find_element(By.XPATH, '//*[@id="input-name1"]').send_keys('WOOP WOOP')
    driver.find_element(By.XPATH, '//*[@id="input-meta-title1"]').send_keys('WOOOP')
    cmd = 'document.querySelector("#language1 > div:nth-child(2) > div > div > div.note-editing-area > div.note-editable.panel-body > p").innerHTML = "' + txt + '";'
    driver.execute_script(cmd)
    driver.find_element(By.XPATH, '//*[@id="form-product"]/ul/li[2]/a').click()
    driver.find_element(By.XPATH, '//*[@id="input-model"]').send_keys("WOOP")
    driver.find_element(By.XPATH, '//*[@id="input-price"]').send_keys("100")

    driver.find_element(By.XPATH, '//*[@id="content"]/div[1]/div/div/button').click()


def addcart(driver):
    # TIENDA

    driver.get("http://localhost")

    # Find Product 1
    driver.find_element_by_xpath('//*[@id="search"]/input').clear()
    driver.find_element_by_xpath('//*[@id="search"]/input').send_keys('super')
    driver.find_element_by_xpath('//*[@id="search"]/div/button').click()
    driver.find_element_by_xpath('//*[@id="content"]/div[3]/div/div/div[2]/div[1]/h4/a').click()
    driver.find_element_by_xpath('//*[@id="button-cart"]').click()

    #FInd product 2
    driver.find_element_by_xpath('//*[@id="search"]/input').clear()
    driver.find_element_by_xpath('//*[@id="search"]/input').send_keys('woop')
    driver.find_element_by_xpath('//*[@id="search"]/div/button').click()
    driver.find_element_by_xpath('//*[@id="content"]/div[3]/div/div/div[2]/div[1]/h4/a').click()
    driver.find_element_by_xpath('//*[@id="button-cart"]').click()

    # Go to cart
    driver.find_element_by_xpath('//*[@id="cart"]/button').click()
    driver.find_element_by_xpath('//*[@id="cart"]/ul/li[2]/div/p/a[1]').click()

    #checkout
    driver.find_element_by_xpath('//*[@id="content"]/div[3]/div[2]/a').click()

    try:
        radio = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, 'input[name="account"][value="guest"]'))
        )
        radio.click()
    except:
        print("FAILED TO REGISTER")
        exit()
        
    driver.find_element_by_xpath('//*[@id="button-account"]').click()

    # Fill out guest data
    try:
        name = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.NAME, 'firstname'))
        )
        name.send_keys(rand_str(10))
    except:
        print("FAILED TO REGISTER")
        exit()

    driver.find_element_by_name('lastname').send_keys(rand_str(10))
    driver.find_element_by_id('input-payment-email').send_keys(rand_str(10) + '@example.com')
    driver.find_element_by_name('telephone').send_keys(randomCard(10))
    driver.find_element_by_name('address_1').send_keys(rand_str(10))
    driver.find_element_by_name('city').send_keys(rand_str(10))
    driver.find_element_by_name('postcode').send_keys(randomCard(5))
    countries = Select(driver.find_element(By.ID, "input-payment-country"))
    countries.select_by_value("138")
    regions = Select(driver.find_element(By.ID, "input-payment-zone"))
    regions.select_by_value("2153")
    driver.find_element_by_id('button-guest').click()

    # Delivery method
    try:
        element = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.ID, 'button-shipping-method'))
        )
        element.click()
    except:
        print("FAILED TO REGISTER 1")
        exit()

    # Payment method
    try:
        element = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.NAME, 'agree'))
        )
        element.click()
        driver.find_element_by_id('button-payment-method').click()
    except:
        print("FAILED TO REGISTER 2")
        exit()
    
    

    # CONFIRM
    try:
        element = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.ID, 'button-confirm'))
        )
        element.click()
    except:
        print("FAILED TO REGISTER 3")
        exit()

    #driver.find_element_by_xpath()
    #driver.find_element_by_xpath()

if __name__ == '__main__':
    driver = webdriver.Firefox()
    addProds(driver)
    addcart(driver)