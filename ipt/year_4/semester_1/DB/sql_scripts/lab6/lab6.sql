USE bookkeeping
GO


--CREATE VIEW [Обладнання МВО] AS
--SELECT E.name [Назва], E.price [Вартість], E.residualValue [Залишкова вартість], MRP.fullName [Власник] 
--FROM Equipment E
--JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson

SELECT * FROM [Обладнання МВО]

SELECT * FROM [Обладнання МВО]
WHERE [Власник] = N'Petrov Ivan Nikolaevich'


--CREATE VIEW [Обладнання підрозділів] AS
--SELECT E.name [Назва], E.price [Вартість], E.residualValue [Залишкова вартість], MRP.fullName [Власник], S.name [Підрозділ]
--FROM Equipment E
--JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
--JOIN Subdivisions S ON S.id = MRP.subdivision

SELECT * FROM [Обладнання підрозділів]

SELECT * FROM [Обладнання підрозділів]
WHERE [Підрозділ] = N'General Managment'


--CREATE VIEW [Вартість обладнання підрозділів] AS
--SELECT S.name [Підрозділ], SUM(E.price) [Вартість обладнання]
--FROM Equipment E
--JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
--JOIN Subdivisions S ON S.id = MRP.subdivision
--GROUP BY S.name

SELECT * FROM [Вартість обладнання підрозділів]

SELECT * FROM [Вартість обладнання підрозділів]
WHERE [Підрозділ] = N'General Managment'