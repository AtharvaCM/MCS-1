let $path:=doc("/home/atharvacm/MCS-1/ADC/XML/company.xml")

for $emp in $path/companyDB/employees/employee
	where $emp[@worksFor="5"]
	return
		<Employee>
		 	{$emp/fname} {$emp/lname}
		</Employee>
