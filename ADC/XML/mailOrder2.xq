let $path:=doc("/home/atharvacm/MCS-1/ADC/XML/mailOrder.xml")

let $parts:=$path/mailorder/parts/part[price<20.00]
let $odetails:=$path/mailorder/odetails/odetail[pno=data($parts/pno)]
let $order1:=$path/mailorder/orders/order[ono=data($odetails/ono)]
let $cust:=$path/mailorder/customers/customer[cno=data($order1/cno)]

for $i in $cust
	return $cust/cname
