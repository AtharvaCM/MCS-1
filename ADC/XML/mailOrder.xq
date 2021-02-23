let $path:=doc("/home/atharvacm/MCS-1/ADC/XML/mailOrder.xml")

let $city_zip:=$path/mailorder/zipcodes/zipcode[city="Wichita"]
let $emp:=$path/mailorder/employees/employee[zip=data($city_zip/zip)]
let $order1:=$path/mailorder/orders/order[eno=data($emp/eno)]
let $cust:=$path/mailorder/customers/customer[cno=data($order1/cno)]

for $i in $cust
	return $cust/cname
