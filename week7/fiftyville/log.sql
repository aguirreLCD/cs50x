-- Keep a log of any SQL queries you execute as you solve the mystery.

-- the theft took place on July 28, 2020 and that it took place on Chamberlin Street.
-- Start by looking for a crime scene report that matches the date and the location of the crime.
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";

-- each of their interview transcripts mentions the courthouse.
-- sqlite> .schema interviews
-- SELECT transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28;
-- SELECT name, transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28;
SELECT name, transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28 AND transcript LIKE '%courthouse%';

-- Ruth: look for cars that left the parking lot in that time frame.
-- .schema courthouse_security_logs
SELECT id, activity, license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 30
AND activity = "exit";

-- Eugene: ATM on Fifer Street / bank_accounts
-- sqlite> .schema atm_transactions
SELECT id, account_number, transaction_type, amount FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28
AND atm_location = "Fifer Street"
AND transaction_type = "withdraw";

SELECT * FROM bank_accounts JOIN people ON person_id = people.id WHERE license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 30
AND activity = "exit");

-- Raymond: phone calls, flights, airports, passengers, people
-- purchase the flight ticket
SELECT id, caller, receiver FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28
AND duration <= 60;

-- person_id | id | name | phone_number | passport_number | license_plate | account_number
-- 686048 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X | 49610011
-- 514354 | 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE | 26013199

SELECT person_id, id, name, phone_number, passport_number, license_plate, account_number FROM bank_accounts
JOIN people ON person_id = people.id
WHERE license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 30
AND activity = "exit")
AND account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28
AND atm_location = "Fifer Street"
AND transaction_type = "withdraw")
AND phone_number IN
(SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
AND passport_number IN
(SELECT passport_number FROM passengers JOIN flights ON flight_id = flights.id WHERE year = 2020 AND month = 7 AND day = 29);

-- phone caller - Ernest
SELECT name FROM bank_accounts JOIN people ON person_id = people.id
WHERE license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit")
AND account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28
AND atm_location = "Fifer Street" AND transaction_type = "withdraw")
AND phone_number IN
(SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration <= 60)
AND passport_number IN
(SELECT passport_number FROM passengers JOIN flights ON flight_id = flights.id WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 05 AND 08
AND origin_airport_id IN (SELECT id FROM airports WHERE city="Fiftyville"));

-- SELECT * FROM flights WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 06 AND 08;

-- SELECT origin_airport_id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 06 AND 08;

-- sqlite> SELECT * FROM flights WHERE origin_airport_id = 8 AND year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 05 AND 08;

-- SELECT full_name, city FROM airports JOIN flights ON origin_airport_id = airports.id
-- WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 05 AND 08 AND origin_airport_id = 8;

-- sqlite> SELECT * FROM flights WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 05 AND 08;

-- SELECT full_name, city FROM airports JOIN flights ON destination_airport_id = airports.id
-- WHERE year = 2020 AND month = 7 AND day = 29 AND hour > 8;

-- SELECT passport_number FROM passengers JOIN flights ON flight_id = flights.id WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 05 AND 08;

-- SELECT passport_number FROM passengers JOIN flights ON flight_id = flights.id WHERE year = 2020 AND month = 7 AND day = 29 AND hour > 8;

-- SELECT name FROM people JOIN passengers, flights ON flight_id = flights.id WHERE year = 2020 AND month = 7 AND day = 29 AND hour > 8;

SELECT name FROM people
JOIN passengers, flights, airports
ON flight_id = flights.id
AND origin_airport_id = airports.id
AND passengers.passport_number = people.passport_number
WHERE year = 2020
AND month = 7
AND day = 29
AND hour BETWEEN 05 AND 08
AND origin_airport_id = 8;

SELECT name FROM people
JOIN passengers, flights, airports, bank_accounts
ON flight_id = flights.id
AND origin_airport_id = airports.id
AND passengers.passport_number = people.passport_number
AND person_id = people.id
WHERE year = 2020
AND month = 7
AND day = 29
AND hour BETWEEN 05 AND 08
AND origin_airport_id = 8
AND license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit")
AND phone_number IN
(SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
AND account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28
AND atm_location = "Fifer Street" AND transaction_type = "withdraw");



-- SELECT name FROM phone_calls JOIN people
-- WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
-- AND phone_number IN people.phone_number;

-- SELECT caller, name FROM phone_calls JOIN people
-- WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
-- AND phone_number IN
-- (SELECT receiver FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60);

-- SELECT receiver, name FROM phone_calls JOIN people
-- WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
-- AND phone_number IN
-- (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60);


-- SELECT caller, name FROM phone_calls JOIN people
-- WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
-- AND phone_number IN
-- (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60);


-- SELECT receiver, name FROM phone_calls JOIN people
-- WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
-- AND phone_number IN
-- (SELECT receiver FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60);


SELECT caller, name, duration FROM phone_calls JOIN people
ON caller = phone_number
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
AND caller IN
(SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
ORDER BY duration DESC;

SELECT receiver, name, duration FROM phone_calls JOIN people
ON receiver = phone_number
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
AND receiver IN
(SELECT receiver FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
ORDER BY duration DESC;

-- SELECT caller, name, receiver, name, duration FROM phone_calls JOIN people
-- ON caller = phone_number
-- WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
-- AND caller IN
-- (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
-- ORDER BY duration DESC;

-- SELECT * FROM phone_calls JOIN people
-- ON caller = people.phone_number
-- -- AND receiver = people.phone_number
-- WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
-- AND caller IN
-- (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
-- AND receiver IN
-- (SELECT receiver FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
-- ORDER BY duration DESC;

-- SELECT * FROM people
-- LIMIT 5;

-- SELECT * FROM phone_calls
-- LIMIT 5;


SELECT city FROM airports
JOIN flights, passengers, people
ON destination_airport_id = airports.id
AND flight_id = flights.id
AND passengers.passport_number = people.passport_number
WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 5 AND 8;


-- SELECT name, city FROM people, airports
-- JOIN flights, passengers
-- ON destination_airport_id = airports.id
-- AND flight_id = flights.id
-- AND passengers.passport_number = people.passport_number
-- WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 5 AND 8;




SELECT name FROM people
JOIN passengers, flights, airports, bank_accounts
ON flight_id = flights.id
AND origin_airport_id = airports.id
AND passengers.passport_number = people.passport_number
AND person_id = people.id
WHERE year = 2020
AND month = 7
AND day = 29
AND hour BETWEEN 05 AND 08
AND origin_airport_id = 8
AND license_plate IN
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit")
AND phone_number IN
(SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
AND account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28
AND atm_location = "Fifer Street" AND transaction_type = "withdraw");


-- SELECT name FROM people

-- SELECT * FROM passengers WHERE passport_number IN
-- (SELECT passport_number FROM passengers JOIN flights ON flight_id = flights.id WHERE year = 2020 AND month = 7 AND day = 29 AND hour BETWEEN 05 AND 08
-- AND origin_airport_id IN (SELECT id FROM airports WHERE city="Fiftyville"));

