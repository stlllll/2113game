# 2113game
2113 group project
Group members: Fang Jiahe 3035772482
               Sha Taole  3035770898

Discription of the game: We are inspired by the currently popular game "Life Restart", and decide to design a more vivid and more complex game, named "HKU Restart". The player will experience the life of a HKU student, and try to complete as many tasks as possible.

Game rules: The aim of this game is to complete as many tasks as possible.  (See below to find details about tasks) 

Game Process: The game process includes 8 rounds, and each round consists of 3 sessions.
Each round represents a semester, and the 3 sessions are "semester start","midterm" and "Final Exam Period" respectively.
When a new game starts, the player needs to choose to be a student from 1.local 2.India 3.Mainland China 4.Korea, and start his/her university life with some special initial abilities. (See below to find details about ability)
Then the player enters the fisrt round, a semester.
            
round process:
1.choose 1~4 tasks as "target tasks" for this semester.
2.go through sessions for three times.

session process:
(1)some random events happen and may influence your decision.(Like one course have a good lecturer, and you can develop more ability spending the same time. Then you may consider spend more time on study)
(2)decide how to distribute the time on different things (see below to find details about "spending time on things").
(3)According to the above decision, the player's corresponding ability get improved.
                              
3. After the final, the player has a corresponding probability to accomplish one of the 'target tasks' according to one or some certain abilities.

After 8 semesters the student graduates. A transcript of the student will be generated according to accomplished tasks and outstanding abilities.
            
The total six tasks include 
1.Join student associations 
2.Fall in love 
3.GPA higher than 4 
4.enjoy hall life 
5.do part time job 
6.faculty task
            
The sixth task is a flexible task depending on which faculty the student belongs to. 
1.Science&Engineer students: be a research assistant
2.Law students: intern at a law firm 
3.Business students: find a job 
4.Art&Social Science students: publish a paper
            
The ability of a student includes 
1.learning ability 
2.executive ability 
3.charm 
4.social skills 
5.wealth

Every ability of student is measured by a score.
Overally, with stronger abilities, the player has a higher probability to accomplish tasks at the end of a semester.
Some tasks only depend on one aibility. For example, the probality of accomplishing 'GPA higher than 4' only depends on 'learning ability'. 
Some tasks are multi-ability dependent. Like the probability of accomplishing 'enjoy hall life' depends on 'charm' and 'social skills'.

Spending time on certain things can improve the player's corresponding ability. 
For instance, If a player choose to spend more time on studying, his/her learning ability will be improved. 
In every session(start of term, midterm, final) the player will have points(time) to distribute on different things.
Note student having higher learning ability will have more points(time) to distribute on different things.
There are 5 things to do 
1.study 
2.shopping 
3.socialize 
4.contribute to student associations 

Features to implement:1.main function to run the game process
                      2.store the game status 
                      3.calculate the probabilities for many steps in this game
                      4.randomly happen some unexpected things
                      5.calculate the ability, tasks and so on
                      5.function to display the transcript
How the requirements support it:1.random numbers help with the probability.
                                2.It takes some time to go through the whole game, so we store the game status in a txt file when play exits.
                                3.To speed up compilation and reduce hardware stress, we reuse functions of 'round' and 'seesion'.
                                4.We use some variables as sidecar variables to create more probabilities and make it more like real life.
                                5.The number of functions used in this project is large, so using multiple files helps with coding and debugging.
                                6.This helps us better coorperate, as we can understand what each other means with standard indentation and naming.
                                7.We hide some easter eggs:)
            
