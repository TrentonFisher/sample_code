###################### 
# Course: COMP 1113, 
# Assigment 8, Question 1 
# Author: Trenton Fisher 
# Student ID: 100162307
# email address: 162307f@acadiau.ca
#########################

import requests

repeatSearch = "-_-"

def getDataFromApi():
    url = "https://data.novascotia.ca/resource/m862-kmjy.json?$limit=20000"
    response = requests.get(url)
    if (response.status_code == 200):
        return response.json()
    else:
        return "Error Retrieving Data"

data = getDataFromApi()    

while repeatSearch != "":  
    
    municipalities = [item.get("geography") for item in data]
    
    municipalities = set(municipalities)
    
    municipalities = list(municipalities)
    
    municipalities = sorted(municipalities)
    
    for (index,mun) in enumerate(municipalities):
        print(f"{index} {mun}")
        
    userChoice = int(input("Please select a municipality: "))
    
    municipality = municipalities[userChoice]
    
    print('\n' + municipality)
    
    year = input("Enter a year for crime violations: ")
    
    print('\nThe entered year is ' + year + '\n')
    
    crimeViolations = [crimes for crimes in data if crimes.get("year") == year and crimes.get("geography") == municipality]
    
    for vio in crimeViolations:
        print(f"\n{vio.get('violations')} Incidents: {vio.get('incidents')} ")

    totalIncidents = sum([int(i.get('incidents', 0)) for i in data if i.get('geography') == municipality and i.get('year') == str(year)])
    
    print('\n' + "Total number of incidents: " + str(totalIncidents))

    repeatSearch = input("Would you like to search more crime data? Enter any key to continue or nothing to stop: ")