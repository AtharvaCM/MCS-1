let $path := doc("/home/atharva-cm/MCS-1/ADC/XML/revision/mailOrder.xml")

let $zips := $path//customers/customer/zip

for $i in $path//customers/customer
	for $j in $path//customers/customer[2]
	return 
		<result>
		{
		if($i/zip = $j/zip)
		then $i/cname | $j/cname
		else $i/cno
		}
		</result>
