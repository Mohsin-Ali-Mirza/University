import unittest
from selenium import webdriver

class SeleniumTest(unittest.TestCase):
    
    def setUp(self):
        self.driver = webdriver.Chrome()
        
    def test_ValidateCorrectAnswer(self):
        print("Should Validate Correct Answer . ==")
        self.driver.get(r'C:\Users\Mohsin\OneDrive\Desktop\SE_Ass2\index.html')
        search_box = self.driver.find_element('name','answer')
        submit_button = self.driver.find_element('xpath','//button[@onclick="checkAnswer()"]')
        search_box.send_keys('8')
        submit_button.click()
        result = self.driver.find_element('id','result')
        print(result)
        self.assertEqual('You are correct!', result.text)

    def test_DefectCorrectAnswer(self): # defect
        print("Should be Defect Correct Answer F ==")
        self.driver.get(r'C:\Users\Mohsin\OneDrive\Desktop\SE_Ass2\index.html')
        search_box = self.driver.find_element('name','answer')
        submit_button = self.driver.find_element('xpath','//button[@onclick="checkAnswer()"]')
        search_box.send_keys('8')
        submit_button.click()
        result = self.driver.find_element('id','result')
        print(result)
        self.assertEqual('You must enter a number and not a string.', result.text)

    def test_ValidateString(self):
        print("Should be Validate String . ==")
        self.driver.get(r'C:\Users\Mohsin\OneDrive\Desktop\SE_Ass2\index.html')
        search_box = self.driver.find_element('name','answer')
        submit_button = self.driver.find_element('xpath','//button[@onclick="checkAnswer()"]')
        search_box.send_keys('mohsin')
        submit_button.click()
        result = self.driver.find_element('id','result')
        print(result)
        self.assertEqual('You must enter a number and not a string.', result.text)

    def test_defectString(self): #defect test
        print("Should be Defect Negative F ==")
        self.driver.get(r'C:\Users\Mohsin\OneDrive\Desktop\SE_Ass2\index.html')
        search_box = self.driver.find_element('name','answer')
        submit_button = self.driver.find_element('xpath','//button[@onclick="checkAnswer()"]')
        search_box.send_keys('mohsin')
        submit_button.click()
        result = self.driver.find_element('id','result')
        print(result)
        self.assertEqual('You are correct!', result.text)


    def tearDown(self):
        self.driver.quit()

if __name__ == '__main__':
    unittest.main()