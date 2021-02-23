let $path:=doc("/home/atharvacm/MCS-1/ADC/XML/mailOrder.xml")

let $parts:=$path/mailorder/parts/part[price>50.00]
let $odetails:=$path/mailorder/odetails/odetail[pno=data($parts/pno)]
let $order1:=$path/mailorder/orders/order[ono=data($odetails/ono)]
let $emp:=$path/mailorder/employees/employee[eno=data($order1/eno)]
let $city:=$path/mailorder/zipcodes/zipcode[zip=data($emp/zip)]

for $i in $emp
	return 
		<records>
			{$emp/ename}{$city/city}
		</records>
