let $path := doc("/home/atharva-cm/MCS-1/ADC/XML/revision/company.xml")

for $e in $path/companyDB/employees/employee
	where count($e/dependents/dependent) >= 2
	return
	<result>
		{$e/fname}
		{$e/lname}
	</result>
