USE bookkeeping
GO


--CREATE VIEW [���������� ���] AS
--SELECT E.name [�����], E.price [�������], E.residualValue [��������� �������], MRP.fullName [�������] 
--FROM Equipment E
--JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson

SELECT * FROM [���������� ���]

SELECT * FROM [���������� ���]
WHERE [�������] = N'Petrov Ivan Nikolaevich'


--CREATE VIEW [���������� ��������] AS
--SELECT E.name [�����], E.price [�������], E.residualValue [��������� �������], MRP.fullName [�������], S.name [ϳ������]
--FROM Equipment E
--JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
--JOIN Subdivisions S ON S.id = MRP.subdivision

SELECT * FROM [���������� ��������]

SELECT * FROM [���������� ��������]
WHERE [ϳ������] = N'General Managment'


--CREATE VIEW [������� ���������� ��������] AS
--SELECT S.name [ϳ������], SUM(E.price) [������� ����������]
--FROM Equipment E
--JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
--JOIN Subdivisions S ON S.id = MRP.subdivision
--GROUP BY S.name

SELECT * FROM [������� ���������� ��������]

SELECT * FROM [������� ���������� ��������]
WHERE [ϳ������] = N'General Managment'