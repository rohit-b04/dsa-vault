select p.firstName, p.lastName, a.city, a.state from Person as p left join Address as a 
on p.personId = a.personId union
select p1.firstName, p1.lastName, a1.city, a1.state from Person as p1 right join Address as a1
on p1.personId = a1.personId where p1.firstName is not null;