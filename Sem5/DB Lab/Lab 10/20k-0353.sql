--1
create table persons(
personID int primary key,
FirstName varchar(25),
LastName varchar(25),
Address varchar(50),
City varchar(20),
age int 
);

insert into persons values(1,'w','x','gulshan','karachi',12);
insert into persons values(2,'x','r','gulshan','karachi',25);
insert into persons values(3,'y','e','gulshan','karachi',25);
insert into persons values(4,'z','f','gulshan','karachi',25);
insert into persons values(5,'w','x','gulshan','karachi',25);

savepoint after_5;

insert into persons values(6,'w','x','gulshan','karachi',25);
insert into persons values(7,'Erum','r','gulshan','karachi',25);
insert into persons values(8,'y','e','gulshan','karachi',28);
insert into persons values(9,'z','f','gulshan','karachi',25);
insert into persons values(10,'w','x','gulshan','karachi',25);

update persons set FirstName='Rida' where personID=7;

rollback to SAVEPOINT after_5;

select * from persons;

--2
--taking id=5 instead of 8
--and taking 25 instead of 28
update persons set age=30 where personID=5;





