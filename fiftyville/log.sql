-- Keep a log of any SQL queries you execute as you solve the mystery.

----------------------------------------------------------------------------------------------------------------------------------------------------
-- 1) Get more information about the theft

SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';

-- Clues: 10:15am, Humphrey Street bakery, 3 witnesses.

------------------------------------------------------------------------------------------------------------------------------------------------------
-- 2)Check the interviews

SELECT *
FROM interviews
WHERE month = 7 AND day = 28 AND year = 2021;

-- Clue:  Witness 1 - Ruth: Within 10 minutes of the theft, she saw the thief get into a car in the bakery parking lot and drive away.
-- Do: Check security camera footage for cars that left the parking lot in that time frame.

-- Clue: Witness 2 - Eugene: Saw the thief by the ATM on Leggett Street withdrawing money.
-- Do: Check ATM records on Leggett Street

-- Clue: Witness 3 - Raymond: As the thief was leaving, they called someone for less than a minute. Planning to take the earliest flight out of fiftyville
--       tomorrow (29.07). The thief asked the person on other end to buy the ticket.
-- Do: Check phone call records for a call less than a minute long
-- Do: Check For fiftyville airports and earliest flights on 29.07

-------------------------------------------------------------------------------------------------------------------------------------------------------
--3) Check ATM transactions and accounts

SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location ='Leggett Street';

-- Clue: There were 8 accounts withdrawing money at Leggett Street ATM that day:

-- 28500762 amount: 48
-- 28296815 amount: 20
-- 76054385 amount: 60
-- 49610011 amount: 50
-- 16153065 amount: 80
-- 25506511 amount: 20
-- 81061156 amount: 30
-- 26013199 amount: 35

-- Do: Check price of flight ( if can be checked )
-- Do: Check person ID if flight prices match any withdrawal

-------------------------------------------------------------------------------------------------------------------------------------------------------
-- 4) Check flights on 29.07

SELECT * FROM airports WHERE city = 'Fiftyville';

-- Clue: Fiftyville Regional Airport (CSF) , ID - 8

SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 AND year = 2021;

-- Clue: Earliest flight from Fiftyville on 29.07 is on 8:20 to destination airport ID 4

SELECT * FROM airports WHERE id = 4;

-- Clue : The thief is flying to LaGuardia Airport (LGA) in New York City on 29.07 8:20

---------------------------------------------------------------------------------------------------------------------------------------------------------
-- 5) Check Phonecalls on 28.07 that are less than a minute long

SELECT * FROM phone_calls WHERE year = 2021 AND day = 28 AND month = 7 AND duration < 60;

-- Clue:
-- Caller: (130) 555-0289    Receiver: (996) 555-8899
-- Caller: (499) 555-9472    Receiver: (892) 555-8872
-- Caller: (367) 555-5533    Receiver: (375) 555-8161
-- Caller: (499) 555-9472    Receiver: (717) 555-1342
-- Caller: (286) 555-6063    Receiver: (676) 555-6554
-- Caller: (770) 555-1861    Receiver: (725) 555-3243
-- Caller: (031) 555-6622    Receiver: (910) 555-3251
-- Caller: (826) 555-1652    Receiver: (066) 555-9701
-- Caller: (338) 555-6650    Receiver: (704) 555-2131

----------------------------------------------------------------------------------------------------------------------------------------------------------
-- 6) Check security camera footage

-- get license plates
SELECT * FROM bakery_security_logs WHERE year = 2021 AND  month = 7 AND day = 28 AND minute < 25 AND minute > 15  AND hour = 10;

-- get additional data for each
SELECT * FROM people WHERE license_plate = '0NTHK55';

-- Clue: In the time frame 10:15 - 10:15 these cars left the bakery parking lot:

-- 5P2BI95 (Vanessa)
-- 94KL13X (Bruce)
-- 6P58WS2 (Barry)
-- 4328GD8 (Luca)
-- G412CB7 (Sofia)
-- L93JTIZ (Iman)
-- 322W7JE (Diana)
-- 0NTHK55 (Kelsey)

------------------------------------------------------------------------------------------------------------------------------------------------------------
--7) Analyze the data from phone calls

-- get caller data
SELECT * FROM people WHERE phone_number IN(SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021 AND duration <60);

-- Clue: People whose phone numbers and licence plate match the suspect profile:

-- Name    Phone Number     Passport     Licence plate
-- Diana   (770) 555-1861   3592750733   322W7JE
-- Sofia   (130) 555-0289   1695452385   G412CB7
-- Kelsey  (499) 555-9472   8294398571   0NTHK55
-- Bruce   (367) 555-5533   5773159633   94KL13X

-------------------------------------------------------------------------------------------------------------------------------------------------------------
--8) check passengers on flight

-- get flight ID
SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 AND year = 2021 AND hour = 8 AND minute = 20;

-- Clue: Flight ID 32

-- Check passengers on flight 32

-- Clue: Passport numbers on flight 32:
-- 3866596772
-- 5140313594
-- 3816396248
-- 8699553201

-- Check passenger data

 SELECT * FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 32);

 --Clue:
 --
 -- Name      Phone number     Passport     License plate
 --
 -- Virginia  (478) 555-1565   3866596772
 -- Austin                     5140313594   P160306
 -- Teresa    (041) 555-4011   8699553201   HW0BF87
 -- Jerry     (558) 555-9741   3816396248   4DD691O

 ---------------------------------------------------------------------------------------------------------------------------------------------------------------
--9) Check phone call data again
SELECT * FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE day = 28 AND year = 2021 AND month = 7 AND duration < 60);
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND year = 2021 AND month = 7 AND duration < 60);

-- Caller: (130) 555-0289 (Sofia)    Receiver: (996) 555-8899 (Jack)
-- Caller: (499) 555-9472 (Kelsey)   Receiver: (892) 555-8872 (Larry)
-- Caller: (367) 555-5533 (Bruce)    Receiver: (375) 555-8161 (Robin)
-- Caller: (499) 555-9472 (Kelsey)   Receiver: (717) 555-1342 (Melissa)
-- Caller: (286) 555-6063 (Taylor)   Receiver: (676) 555-6554 (James)
-- Caller: (770) 555-1861 (Diana)    Receiver: (725) 555-3243 (Philip)
-- Caller: (031) 555-6622 (Carina)   Receiver: (910) 555-3251 (Jacqueline)
-- Caller: (826) 555-1652 (Kenny)    Receiver: (066) 555-9701 (Doris)
-- Caller: (338) 555-6650 (Benista)  Receiver: (704) 555-2131 (Anna)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

--10) Check bank accounts


SELECT name FROM people WHERE id IN(SELECT person_id FROM bank_accounts WHERE account_number IN(SELECT account_number FROM atm_transactions WHERE day = 28 AND year = 2021 AND month = 7 AND atm_location = 'Leggett Street'));

-- People who made a withdrawal:

-- Kenny
-- Iman
-- Benista
-- Taylor
-- Brooke
-- Luca
-- Diana
-- Bruce
-- Kaelyn

-----------------------------------------------------------------------------------------------------------------------------------------------------

-- Bruce must be the thief, because his name appears in all suspect lists
-- He fled to New York City
-- His accomplice must be Robin






















