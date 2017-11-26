--ALTER TABLE MaterialResponsiblePeople DROP CONSTRAINT MaterialResponsiblePeopleCheck;
ALTER TABLE MaterialResponsiblePeople WITH NOCHECK 
ADD CONSTRAINT fullNameCheck CHECK (fullName LIKE ('_____[ ]_____[ ]__________'));
ALTER TABLE MaterialResponsiblePeople DROP CONSTRAINT fullNameCheck;