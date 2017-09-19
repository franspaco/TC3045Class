require 'watir'
browser = Watir::Browser.new :firefox

browser.goto 'http://blazedemo.com/'

browser.select_list(:name, "fromPort").select("Mexico City")

browser.select_list(:name, "toPort").select("London")

browser.form(:action, 'reserve.php').submit

browser.inputs(:value, "Choose This Flight").last.click
#browser.form(:name, 'L4346').submit


browser.text_field(:id => "inputName").set("hola")
browser.text_field(:id => "address").set("hola")
browser.text_field(:id => "city").set("hola")
browser.text_field(:id => "state").set("hola")
browser.text_field(:id => "zipCode").set("hola")

browser.select_list(:id, "cardType").select("visa")

browser.text_field(:id => "creditCardNumber").set("0118 999 881 999 119 7253")
browser.text_field(:id => "creditCardMonth").set("12")
browser.text_field(:id => "creditCardYear").set("2045")
browser.text_field(:id => "nameOnCard").set("WOOP WOOP")

browser.form(:action, "http://blazedemo.com/confirmation.php").submit
