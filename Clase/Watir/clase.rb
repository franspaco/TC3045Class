require 'watir'
browser = Watir::Browser.new :firefox

browser.goto 'http:nitrowriters.com/form/form.html'

browser.text_field(:id => "my_text_field").set("hola")
browser.textarea(:id => "a_text_area").set("banana")
browser.radio(:name => 'familiar_rails', :value => '3').set

browser.text_field(:id => "favorite_1").set("woop woop")
browser.text_field(:id => "favorite_2").set("dooly do")

checks = browser.checkboxes(:name => /element_14/)
checks.each do |check|
    check.set
end


browser.select_list(:id, "usage").select("1")

puts browser.select_list(:id => "usage").options(:index,3)

browser.file_field(:id,"give_me_a_file").set("C:\\Users\\franspaco\\empty.txt")
