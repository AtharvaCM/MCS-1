let $path:=doc("/home/atharvacm/MCS-1/ADC/XML/company.xml")

for $emp in $path/companyDB/employees/employee
	where count($emp/dependents/dependent) >= 2
	return
		<Employee>
		 	{$emp/fname} {$emp/lname}
		</Employee>
