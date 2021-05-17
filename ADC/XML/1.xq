let $d:=doc("/home/atharva-cm/MCS-1/ADC/XML/company.xml")
for $e in $d/companyDB/employees/employee/dependents/dependent
	where 	contains($e/dob,'APR')
	return $e
