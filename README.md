# 2113game
2113 group project
Group members: Fang Jiahe 
               Sha Taole  3035770898
Discription of the game: We are inspired by the currently popular game "Life Restart", and decide to design a similar but more complex game. It is named "HKU Restart". The                              player will experience the life of a HKU student, and try to complete as many tasks as possible.
Game rules: The aim of this game is to complete as many tasks as possible.  (See below to find details about tasks) 

            Game Process: The game process includes 8 big rounds, and each big round consists of 3 small rounds.
            Every big round represents a semester, and the 3 small rounds are "semester start","midterm" and "Final Exam Period" respectively.
            When a new game starts, the player needs to choose to be a student from 1.local 2.India 3.Mainland China 4.Korea, and start his/her university life with some                   initial ability. (See below to find details about ability)
            Then the player enters the big round, that is, a semester.
            big round process:1.choose 1~4 tasks as "target tasks"
                              2.enter the small round for three times
                                small round process:(1)some unexpected events happen and may influence your decision.(Like you come across a good professor who teaches well,                                                        then you may consider spend more time studying)
                                                    (2)decide how to distribute the time on different things (see below to find details about "spending time on things")
                                                    (3)According to the above decision, the player's corresponding ability get improved.
                              3.Now, due to the ability, the player has a certain possibility to accomplish his/her "target tasks".
            After the end of total 8 big rounds, the student graduates. And due to the total tasks that have been completed, a transcript of the student will be displayed.
            
            The total five tasks include 1.Join student organizations 2.Fall in love 3.get a gpa higher than 4 4.enjoy hall life 5.do part time job 6.a flexible task
            The sixth task is a flexible task depending on which faculty the student belongs to. 
            (1.Get a RA job for Science&Engineer students 2.Find an intern for Law students 3.Find a job for Business students 4.Writing papers for Art&Social Science                     students)
            
            The ability of a student includes 1.learning ability 2.action ability 3.charm 4.social ability 5.money
            Every ability of student has a score (0~10) to represent how strong it is.
            With a stronger certain ability, the player will have higher probability to finish certain tasks at the end of a semester.
            
            Spending some time on some certain things can improve a student's ability. For instance, If a player choose to spend more time on studying, his/her learning                   ability will be improved. Every small round (start, midterm , final), the player will has a chance to choose how to distribute his/her time (a player with                     stronger learning ability will get more time to distribute) on different things.
            There are totally 5 kinds of things to choose. 1.study 2.go shopping 3.social intercourse 4.take responsibilities and contribute to the student organization. 5.do             research
Features to implement:1.main function to run the game process
                      2.store the game status 
                      3.calculate the probabilities for many steps in this game
                      4.randomly happen some unexpected things
                      5.calculate the ability, tasks and so on
                      5.function to display the transcript
How the requirements support it:1.random numbers helps with the probability
                                2.As the game needs lots of time, so we need to store the game status when the player exits
                                3.
                                4.Using another file to store the game status
                                5.The number of functions used in this project is large, so using multiple files helps with coding and debugging
                                6.This helps us better coorperate, as we can understand what each other means with clear indentation and naming 
                                7.
            
