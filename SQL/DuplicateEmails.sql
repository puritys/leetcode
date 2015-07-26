//https://leetcode.com/problems/duplicate-emails/

900 ms
select Email from Person group by Email having count(*) > 1;

898 ms
select Email from (select *,count(*) as num from Person group by Email) as k where k.num > 1;

970 ms
select Email from Person as k where 1 < (select count(*) from Person where Email=k.Email) group by Email;

975 ms
select Email from Person where Id in (select Id from (select Id,count(*) as num from Person group by Email) as k where k.num > 1);

1024 ms
select Email from Person as k where (select count(*) as k from Person where Email=k.Email) > 1 group by Email;

