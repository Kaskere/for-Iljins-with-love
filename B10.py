# Create program both in C++, and Python by making use of described or other functions.
# #Requirements are the same as for the previous task, see published detailed requirements.
# TASK B10. Given three natural numbers which denote date (day, month, year).
# #Create function which returns weekday for that date. - > DONE
# The solution should also contain an auxiliary  function for leap year checking. -> DONE
### easiest ways - date or calendar libraries; in this case no built in libraries are allowed, so
##Zeller’s formula can be used
##############################INPUT################################################
date_str = input('Enter some date in exactly following format: dd mm yyyy \n')
day = int(date_str.split(' ')[0])
month = int(date_str.split(' ')[1])
year = int(date_str.split(' ')[2])

###########################VALIDATES INPUT##################################

if month > 0 and month <= 12:
    print("month ok")
else:
    print("month NOT ok")
##### use dictionaries for day check
lookup_table = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
if not (day >= 1 and day <= lookup_table[month - 1]):
    print("wrong day \n")


## check length of the year
if 1 <= len(str(year)) <= 4:
    print("year ok")
else:
    print("year NOT ok")


#############################DO THE BLACK WORK ##################################################
def day_of_week(year, month, day):
    if (month < 3):
        month += 12
        year -= 1
        # Sakamoto's algorithm to find out the day of week from a given date.
    result = (day + (int((13 * (month - 2)) / 5)) + year + (int(year / 4)) - (int(year / 100)) - (int(year / 400))) % 7
    return int(result) + 1
### make array with week name
week_days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
week_num = day_of_week(year, month, day)
print(week_days[week_num])

# function for determining leap year; source logics from wiki: https://en.wikipedia.org/wiki/Leap_year_problem

def leap_year(year):
    if year % 4 == 0:
        if year % 100 != 0:
            return True
    if year % 400 == 0:
        return True
    return False

if leap_year(year):
    # The format() method allows you format string in any way you want.
    # {0} and {1} are format codes. The format code {0} is replaced by the first argument of
    # format() i.e 12 , while {1} is replaced by the second argument of format() i.e 31 .
    print("{0} is a leap year".format(year))
else:
    print("{0} is not a leap year".format(year))

    #######################LAZY RESERVE SOLUTION DO NOT TAKE THIS INTO ACCOUNT ################################
# import datetime
#
# def day_of_week(date):
#     day = date.weekday()
#     # make array with day names
#     day_name = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
#     return day_name[day]
#
# date_str = input('Enter some date in following format: dd mm yyyy \n')
# # The strptime() method creates a datetime object from the given string.
# #Note: You cannot create datetime object from every string. The string needs to be in a certain format.
# date = datetime.datetime.strptime(date_str, '%d %m %Y')
# print(day_of_week(date))
