### Imports

import speech_recognition as sr
from gtts import gTTS
import playsound
import os
import requests
import yfinance as yf 
import wolframalpha
import translators as ts
import time
import wikipedia
import datetime
import subprocess



# Cryptocurrency API
crypto_api = 'https://api.coingecko.com/api/v3/simple/price?ids=bitcoin%2Clitecoin%2Csolana&vs_currencies=usd'

# Wolfram Alpha API Key
wolfram_api = 'xxx'

# Chuck Norris API
chuck_norris_api = 'https://api.chucknorris.io/jokes/random'

# News API Key
news_api_key = 'xxx'

# Weather API Key
weather_api_key = 'xxx'

# Distance API Key
distance_api_key = 'xxx'


# Capital of a Country
def wolfram_alpha_country_capital(text):
    client = wolframalpha.Client(wolfram_api)
    rult = client.query(text)
    answer = next(rult.rults).text
    answer_split = answer.split()
    capital_rult = 'The capital of ' + answer_split[-1] + ' is ' + answer_split[0]
    print(capital_rult)
    alina_talk(capital_rult)

# Calculator
def wolfram_alpha_calculator(text):
    client = wolframalpha.Client(wolfram_api)
    rult = client.query(text)
    answer = next(rult.rults).text
    print(answer)
    alina_talk('The answer is ' + answer)

# President of a certain country
def wolfram_alpha_prident(text):
    client = wolframalpha.Client(wolfram_api)
    rult = client.query(text)
    answer = next(rult.rults).text
    print(answer)
    alina_talk('The president is ' + answer)

def translator(text):
    alina_talk_ur(ts.google(text, from_language='en', to_language='ur'))

def chuck_norris():
    cn_data = requests.get(chuck_norris_api)
    cn_json = cn_data.json()
    joke = cn_json['value']
    print(joke)
    alina_talk(joke)

def get_news():
    news_url = 'https://newsapi.org/v2/top-headlines?country=us&apiKey=' + news_api_key
    news = requests.get(news_url).json()
    articles = news['articles']
    
    news_headlines = []
    for art in articles:
        news_headlines.append(art['title'])
    
    for i in range(3):
        print(news_headlines[i])
        alina_talk(news_headlines[i])

def get_weather():
    alina_talk('No problem, I will look it up for you. What city are you interested in?')
    weather_input = alina_listen()
    print(weather_input)
    
    weather_url = 'https://api.weatherbit.io/v2.0/current?city=' + weather_input + '&key=' + weather_api_key
    weather = requests.get(weather_url).json() 
    temperature = weather['data'][0]['temp']
    description = weather['data'][0]['weather']['description']
    weather_rult = 'The temperature in ' + weather_input + ' is ' + str(temperature) + ' degrees and you can see ' + description
    print(weather_rult)
    alina_talk(weather_rult)
    

def distance_info():
    alina_talk('Sure, let me know the starting point')
    location_one = alina_listen()
    time.sleep(1)
    alina_talk('Allright, and now tell me the final destination')
    location_two = alina_listen()
    alina_talk('Give me one moment, I will use my smart brain to calculate the distance for you')
    dist_url = 'http://www.mapquestapi.com/directions/v2/route?key=' + distance_api_key + '&from=' + location_one +'&to=' +location_two + '&unit=k'
    dist_request = requests.get(dist_url).json()
    distance = round(dist_request['route']['distance'],2)
    distance_rult = 'The distance between ' + location_one +' and ' + location_two + ' is ' + str(distance) + ' kilometers'
    print(distance_rult)
    alina_talk(distance_rult)

def wikipedia_info():
    alina_talk('I am happy to help. Let me know what I should search for you on Wikipedia?')
    wiki_listen = alina_listen()
    wiki_rult = wikipedia.summary(wiki_listen, sentences=1)
    print(wiki_rult)
    alina_talk(wiki_rult)

def time_now():
    today_date = datetime.datetime.now()
    hour = today_date.strftime("%I")
    minute = today_date.strftime("%M")
    meridiem = today_date.strftime("%p") 
    time_now = 'It is ' + hour + ':' + minute + ' ' + meridiem
    print(time_now)
    alina_talk(time_now)

def weekday_now():
    weekday_today = datetime.datetime.now().strftime("%A")
    print(weekday_today) 
    alina_talk(weekday_today)   
    

# convert speech to text so we can use the text for the next step
def alina_listen():
    # create recognizer
    r = sr.Recognizer()
    # what we speak into the microphone should be our source
    with sr.Microphone() as source:
        # use the listen function so the recognizer can cathch the source (our mic)
        audio = r.listen(source)
        text = ''
        
        try:
            text = r.recognize_google(audio) 
        
        except sr.RequestError as re:
            print(re)
        
        except sr.UnknownValueError as uve:
            print(uve)
        
        except sr.WaitTimeoutError as wte:
            print(wte)
    
    text = text.lower()
    return text
            

# convert text to speech
def alina_talk(text):
    # create audio data
    file_name = 'audio_data.mp3'
    # convert text to speech
    tts = gTTS(text=text, lang='en')
    # save file
    tts.save(file_name)
    # play file
    playsound.playsound(file_name)
    # remove file
    os.remove(file_name)

    # convert text to speech (german)
def alina_talk_ur(text):
    # create audio data
    file_name = 'audio_data.mp3'
    # convert text to speech
    tts = gTTS(text=text, lang='ur')
    # save file
    tts.save(file_name)
    # play file
    playsound.playsound(file_name)
    # remove file
    os.remove(file_name)

# create a function which will give us back a reply based on the input text
def alina_reply(text):
    
    s = ""
    ss = ""
    r = ""
   # r = {
        
       # "transcription": None
   # }
    
    # smalltalk - what is your name?
    if 'what' in text and 'name' in text:
        alina_talk('My name is Alina and I am your personal assistant')
        
    # smalltalk - why do you exist?
    elif 'why' in text and 'exist' in text:
        alina_talk('I was created to work for you. I dont need a break and I will never ask for days off')
    
    # smalltalk - when do you sleep?
    elif 'when' in text and 'sleep' in text:
        alina_talk('I never sleep. I was created to support you 24 hours')
        
    # smalltalk- are you stupid?
    elif 'you' in text and 'stupid' in text:
        alina_talk('No, I am not stupid. My grandmother told me that there are no stupid persons out there. '
               + 'I try to give my best everyday and learn continuously')
        
    # Smalltalk - Favorite Movie?
    elif 'favorite' in text or 'favourite' in text and 'movie' in text:
        alina_talk("My favorite movie is Titanic. I watch it with my friends all the time")
    
    # Cryptocurrency - Bitcoin
    elif 'bitcoin' in text:
        rponse = requests.get(crypto_api)
        crypto_json = rponse.json()
        alina_talk('The current price for a Bitcoin is' + str(crypto_json['bitcoin']['usd']) + ' US Dollars')
        
    # Cryptocurrency - Litecoin
    elif 'litecoin' in text:
        rponse = requests.get(crypto_api)
        crypto_json = rponse.json()
        alina_talk('The current price for a Litecoin is' + str(crypto_json['litecoin']['usd']) + ' US Dollars')
    
    # Cryptocurrency - Solana
    elif 'solana' in text:
        rponse = requests.get(crypto_api)
        crypto_json = rponse.json()
        alina_talk('The current price for a Solana Coin is' + str(crypto_json['solana']['usd']) + ' US Dollars')
        
    # Stocks - Apple
    elif 'apple' in text:
        apple = yf.Ticker('AAPL')
        print(apple.info['regularMarketPrice'])
        alina_talk('At this moment you can purchase one Apple Share for ' + str(apple.info['regularMarketPrice']) + ' US Dollars')              
    
    # Stocks - Facebook
    elif 'facebook' in text:
        facebook = yf.Ticker('FB')
        print(facebook.info['regularMarketPrice'])
        alina_talk('At this moment you can purchase one Facebook Share for ' + str(facebook.info['regularMarketPrice']) + ' US Dollars')

    # Stocks - Tesla
    elif 'tesla' in text:
        tesla = yf.Ticker('TSLA')
        print(tesla.info['regularMarketPrice'])
        alina_talk('At this moment you can purchase one Tesla Share for ' + str(tesla.info['regularMarketPrice']) + ' US Dollars')
        
    # Wolfram Alpha - Capital of a Country
    elif 'capital' in text and 'of' in text:
        wolfram_alpha_country_capital(text)
        
    # Wolfram Alpha - Calculator
    elif '+' in text or '-' in text or 'multiply' in text or 'multipled' in text or 'divide' in text or 'root' in text:
        wolfram_alpha_calculator(text)
    
    # Wolfram Alpha - President
    elif 'who' in text and 'president' in text:
        wolfram_alpha_prident(text)
        
    # Translator
    elif 'translate' in text:
        alina_talk('Sure, what do you need me to translate?')
        while True:
            text_to_translate = alina_listen()
            if text_to_translate != 'turn off translator':
                translator(text_to_translate)
            else:
                alina_talk('The translator will be turned off.. What else can I do for you?')
                break
    
    # Chuck Norris Jokes
    elif 'chuck norris' in text:
        chuck_norris()
    
    # Top 3 News- Headlines
    elif 'news' in text:
        alina_talk('Allright, let me tell you the first three headlines')
        get_news()
    
    # Weather
    elif 'weather' in text:
        get_weather()
        
    # Distance
    elif 'distance' in text:
        distance_info()
    
    # Wikipedia
    elif 'wikipedia' in text: 
        wikipedia_info()
    
    # current time
    elif 'time' in text:
        time_now()
    
    # current weekday
    elif 'weekday' in text:
        weekday_now()
    
    elif "remove user from home" in text:
        alina_talk("Tell the user name")
        r =  alina_listen()
        r = "/home" + r
        if os.path.exists(r):
            alina_talk("Are you sure you want to delete " + r + " ?")
            r1 =  alina_listen()
            if "yes" in r1:
                ss = str(subprocess.check_output(['rm',r]))
                print(ss)
                alina_talk("Sucessfully deleted the user.")
            else:
                print("You refused to delete the file.")
                alina_talk("Unable to delete the file.")
    
    elif "delete user permenantly" in text:
        alina_talk("Tell the user name")
        r =  alina_listen()
        r = "/home" + r
        if os.path.exists(r):
            alina_talk("Are you sure you want to permanent delete " + r + " ?")
            r1 =  alina_listen()
            if "yes" in r1:
                ss = str(subprocess.check_output(['deluser','-remove-home',r]))
                print(ss)
                alina_talk("Sucessfully permanent deleted the user.")
            else:
                print("You refused to permanent delete the file.")
                alina_talk("Unable to delete the file.")
        else:
            alina_talk(r + " user does not exists.")
            print(r + " user does not exists.")
            
    elif "delete user" in text:
        alina_talk("Tell the user name")
        r =  alina_listen()
        name = str(r)
        r = "/home" + name
        if os.path.exists(r):
            alina_talk("Are you sure you want to delete " + r + " ?")
            r1 =  alina_listen()
            if "yes" in r1:
                ss = str(subprocess.check_output(['deluser',r]))
                print(ss)
                alina_talk("Sucessfully deleted the user.")
            else:
                print("You refused to delete the file.")
                alina_talk("Unable to delete the file.")
        else:
            alina_talk(r + " user does not exists.")
            print(r + " user does not exists.")
    elif "shutdown" in text:
        os.system("shutdown -h now")
        alina_talk("Shuting Down the PC.")
    elif "list files" in text:
        s = str(subprocess.check_output(['ls']))
        print(s)
        alina_talk("All files prent in the directory " + str(subprocess.check_output(['pwd'])) + " are displayed on terminal.")
        
    elif "list formated files" in text or "list file permissions" in text:
        s = str(subprocess.check_output(['ls','-l']))
        print(s)
        alina_talk("All files prent in the directory " + str(subprocess.check_output(['pwd'])) + " are displayed on terminal with permissions.")

    elif "list hidden files" in text:
        s = str(subprocess.check_output(['ls','-a']))
        print(s)
        alina_talk("All hidden files prent in the directory " + str(subprocess.check_output(['pwd'])) + " are displayed on terminal.")

    elif "current working directory" in text or "where am i standing" in text:
        s = str(subprocess.check_output(['pwd']))
        print(s)

    elif "what is the date today" in text:
        s = str(subprocess.check_output(['date','+%c']))
        print(s)
        alina_talk(s)

    elif "day" in text:
        s = str(subprocess.check_output(['date','+%A']))
        print(s)
        alina_talk(s)

    elif "what is the time" in text:
        s = str(subprocess.check_output(['date','+%T']))
        print(s)
        alina_talk(s)

    elif "calendar" in text:
        s = str(subprocess.check_output(['cal']))
        print(s)
        alina_talk("The Calendar for the " + str(subprocess.check_output(['date','+%B'])) + " month and " + str(subprocess.check_output(['date','+%Y'])) + " year is printed on the screen.")		

    elif "what is the username" in text:
        s = str(subprocess.check_output(['whoami']))
        print(s)
        alina_talk("The user name is "+ s)

    elif "create a random file" in text:
        s = str(subprocess.check_output(['touch','-t']))
        print(s)
        alina_talk("A file has been created in " + str(subprocess.check_output(['pwd'])))

    elif "go to home directory" in text:
        os.system("cd /home")
        alina_talk("You have moved to home directory.")

    elif "go to root directory" in text:
        os.system("cd /")
        print("You have moved to root directory.")
        alina_talk("You have moved to root directory.")

    elif "go to my directory" in text:
        os.system("cd ~")
        print("Your have moved to your directory.")
        alina_talk("Your have moved to your directory.")

    elif "what is the day today" in text:
        import datetime
        now = datetime.datetime.now()
        s = now.strftime("%A")
        alina_talk("Today is " + s)
        print("Today is " + s)

    elif "what is the date today" in text:
        import datetime
        now = datetime.datetime.now()
        s = now.strftime("%d %m %Y")
        alina_talk("Today is " + s)
        print("Today is " + s)

    elif "run ps" in text:
        s = str(subprocess.check_output(['ps','-A']))
        print(s)
        alina_talk("All processes are shown in the terminal")

    elif "show network status" in text:
        s = str(subprocess.check_output(['ifconfig']))
        print(s)
        alina_talk("Network configuration is shown in the terminal")

    elif "create a link" in text:
        alina_talk("Tell the file name")
        r= alina_listen()
        name=r
        if os.path.exists(name):
            alina_talk("What do you want to name the link?")
            r1 =  alina_listen()
            name1 = r1
            os.system("ls -s "+name+" "+name1)
            print("Sucessfully created the link.")
            alina_talk("Sucessfully created the link.")
        else:
            alina_talk("Unable to find the file.")
            print("Unable to find the file.")
    
    elif "delete a file" in text or "remove a file" in text:
        alina_talk("Tell the file name")
        r =  alina_listen()
        print(r)
        name=r
        if os.path.exists(name):
            alina_talk("Are you sure you want to delete " + name + " ?")
            r1 =  alina_listen()
            name1 = r1
            if "yes" in name1:
                os.system("rm " + name1)
                print("Sucessfully deleted the file.")
                alina_talk("Sucessfully deleted the file.")
            else:
                print("You refused to delete the file.")
                alina_talk("Unable to delete the file.")
        else:
            alina_talk("Unable to find the file.")
            print("Unable to find the file.")

    elif "create a file" in text:
        alina_talk("Tell the file name")
        r =  alina_listen() 
        name = r
        if os.path.exists(name):
            alina_talk(name + " already exsists.")
        else:
            os.system("touch " + name)
            alina_talk(name + "file is created.")
            print(name + "file is created.")

    elif "open nano " in text:
        os.system("nano")
        alina_talk("Nano editor is opened")

    elif "open g edit " in text:
        os.system("gedit")
        alina_talk("Gedit editor is opened")

    elif "open sublime" in text:
        os.system("subl")
        alina_talk("Sublime editor is opened")

    elif "open nano editor" in text:
        alina_talk("Tell the file name")
        r =  alina_listen()
        r += ".*"
        ss = str(subprocess.check_output(['nano',r]))
        alina_talk(r + "file is opened.")

    elif "open g edit editor" in text:
        alina_talk("Tell the file name")
        r =  alina_listen()
        r += ".*"
        ss = str(subprocess.check_output(['gedit',r]))
        alina_talk(r + "file is opened.")
    
    elif "open sublime editor" in text:
        alina_talk("Tell the file name")
        r =  alina_listen()
        r += ".*"
        ss = str(subprocess.check_output(['subl',r]))
        alina_talk(r + "file is opened.")

    elif "tell me the file type" in text:
        alina_talk("Tell the file name")
        r =  alina_listen()
        name = r
        if os.path.exists(name):
            ss = str(subprocess.check_output(['file', name]))
            alina_talk(name + "file type is " + ss)
            print(ss)
        else:
            alina_talk("Unable to find the file.")
            print("Unable to find the file.")

    elif "manual" in text:
        alina_talk("Tell the command name")
        r =  alina_listen()
        print(r)
        ss = str(subprocess.check_output(['man',r]))
        print(ss)

    elif "what is the status and configuration of network" in text:
        os.system('ifconfig')

    elif "make a new directory" in text:
        alina_talk("Tell the file name")
        r =  alina_listen()
        name = str(r)
        if os.path.exists(name):
            alina_talk(name + " already exsists.")
        else:
            ss = str(subprocess.check_output(['mkdir',name]))
            alina_talk(name + "directory is created.")
            print(ss)

    elif "login as root user" in text:
        os.system("sudo -s")
        alina_talk("Type your password first")

    elif "list users" in text or "list all users" in text or "list user" in text:
        s = str(os.subprocess.check_output["ls","/home"])
        print(s)
        alina_talk("List of users are " + s)

    elif "add user for login" in text:
        alina_talk("Tell the user name")
        r =  alina_listen()
        name = str(r)
        r = "/home" + r
        if os.path.exists(r):
            alina_talk(r + " user already exists.")
            print(r + " user already exists.")
        else:
            ss = str(subprocess.check_output(['adduser',name]))
            print(ss)
            alina_talk("Sucessfully created the user.")

    
    elif "who created you" in text:
        s = "Following computer scientists created me:\n1. Muhammad Faheem\n2. Mohsin Ali Mirza\n3. Ahmad Aleem."
        alina_talk(s)
        print(s)

        
    elif "goodbye" in text:
            return

     
    else:
        alina_talk('Excuse me, Can you please repeat it?')




### Voice Assistant Execution Section

def execute_assistant():
    # personalize name
    alina_talk('Hi this is Alina, I am here to help you.')
    alina_talk('Hi Miss Safia, what can I do for you?')
    
    while True:
        listen_alina = alina_listen()
        print(listen_alina)
        alina_reply(listen_alina)
        
        # if we use the 'goodbye' keyword, we want to end the while loop and assistant should say goodbye
        if 'goodbye' in listen_alina:
            alina_talk('It was a pleasure to help you, I wish you a wonderful day')    
            break


# call function
if __name__ == "__main__":
    execute_assistant()














