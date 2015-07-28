//https://leetcode.com/problems/consecutive-numbers/


Consecutive Numbers 

select distinct L1.Num from Logs L1, Logs L2, Logs L3 where L2.Id = L1.Id + 1 and L3.Id = L1.Id +2 and L2.Num = L1.Num and L3.Num = L1.Num;

select Num from (select * from Logs as k where k.Num*2 = (select sum(Num) from Logs where Id in (k.Id+1, k.Id+2))) as a;

select Id from (select * from Logs as k where k.Num = (select Num from Logs where Id = k.Id+1) and k.Num = (select Num from Logs where Id = k.Id+2)) as a;


select * from Logs as k where Num in (select Num from Logs group by Num having count(*) > 2) and Num*2 = (select sum(Num) from Logs where Id in (k.Id+1, k.Id+2));
