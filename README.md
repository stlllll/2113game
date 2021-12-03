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
1.choose 3 tasks as "target tasks" for this semester.
2.go through sessions for three times.

session process:
(1)some random events happen and may influence you.(Like one course have a good lecturer, this may make you study easier)
(2)decide how to distribute the time (total 20) on different things (see below to find details about "spending time on things").
(3)According to the above decision, the player's corresponding ability get improved.
                              
3. After the final, through the efforts, the player will have a chance to accomplish the target tasks chosen before

After 8 semesters the student graduates. A transcript of the student will be generated according to accomplished tasks.
            
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
 
 
The following game rules should be hidden to the players. As the key to success of this game, following information should be explored by players themselves!!!

The ability of a student includes 
1.learning ability 
2.executive ability 
3.charm 
4.social skills 
5.wealth

Every ability of student is measured by an integer.
Overally, with stronger abilities, the player has a higher probability to accomplish certain tasks at the end of a semester.

Special abilities (this has a really small influence):
local student have better social skills.
mainland student can have more executive ability.
Korean student have more charm.
Indian student will have better learning ability.

Spending time on certain things can improve the player's corresponding ability. 
For instance, If a player choose to spend more time on studying, his/her learning ability will be improved. 
In every session(start of term, midterm, final) the player will have points(time) to distribute on different things.
Note student having higher learning ability will have more points(time) to distribute on different things.
There are 4 things to do 
1.study 
2.shopping 
3.socialize 
4.contribute to student associations 

Features to implement:1.By using loop (each semester, session), input, output (to interact with the player) to run the game process
                      2.read and save the game status (we use a struct "student" to store the information when run the game; we use a memory.txt, from where we read information at the beginning of the game, and store the information at the end of the game) 
                      3.calculate the probabilities for many steps in this game (like, according to the ability, calculate the probability of accomplishing a certain task)
                      4.randomly happen some unexpected things 
                      5.calculate the ability, tasks and so on (like, spending the time on learning, then the learning ability will be improved)
                      5.function to display the transcript 
How the requirements support it:1.random numbers help with the (3) and (4) features, so that we can generate probabilities and unexpected things.
                                2.We use data structure "student", which contains information about a student, including the name, faculty, round, target tasks, ability and tasks have finished.
                                3.We use the STL container "vector" in our program, which is a way to implement the dynanmic memory. This helped us manage the memory, including reading information from memory.txt, saving information into memory.txt and so on.
                                4.As mentioned before, we use memory.txt to save the game status. File input/output helped us read and save the game status.
                                5.We wrote two functions in other .cpp files (transcript.cpp and print_tasks.cpp). This helped make our structure more clear, and make the debug process easier.
                                6.This helps us better coorperate, as we can understand what each other means with standard indentation and naming. Also, it avoid bugs, as the names for variables are clear, and easy to memory.
                                7.in-code documentation help us better manage the program
            
non-standard C/C++ libraries:None

Compilation and execution: Use "make game" command, and the makefile will help compile it, then, use "./game" to run the program.
