let $path := doc("/home/atharva-cm/MCS-1/ADC/XML/revision/company.xml")

let $projects := $path/companyDB/projects/project[plocation="Stafford"]

let $dept := $path/companyDB/departments/department[@dno = data($projects/@controllingDepartment)]

let $emp := $path/companyDB/employees/employee[@ssn = data($dept/manager/@mssn)]

for $i in $emp
	return
	<result>
		<manager>
		{
			$i/lname |
			$i/address |
			$i/dob	
		}
		</manager>
		<pnumber>
		{
			data($projects/@pnumber)
		}
		</pnumber>
		<controllingDept>
		{
			data($projects/@controllingDepartment)
		}
		</controllingDept>
	</result>
