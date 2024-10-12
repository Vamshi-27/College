# Implement transmission of ping messages/trace route over a network topology consisting of 6 nodes and find the number of packets dropped.

set ns [new Simulator]
set f [open out.tr w]
set nf [open out.nam w]
$ns trace-all $f
$ns namtrace-all $nf

proc finish {} {
    global ns f nf
    $ns flush-trace
    close $f
    close $nf
    exec nam out.nam &
    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$n0 label "ping0"
$n1 label "ping1"
$n2 label "R1"
$n3 label "R2"
$n4 label "ping4"
$n5 label "ping5"

$ns color 1 Red
$ns color 2 Blue
$ns color 3 Green
$ns color 4 Yellow

$ns duplex-link $n0 $n2 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 0.4Mb 30ms DropTail
$ns duplex-link $n3 $n4 1Mb 10ms DropTail
$ns duplex-link $n3 $n5 1Mb 10ms DropTail

set ping0
$ns attach-agent $n0 [new Agent/Ping]

set ping1
$ns attach-agent $n1 [new Agent/Ping]

set ping4
$ns attach-agent $n4 [new Agent/Ping]

set ping5
$ns attach-agent $n5 [new Agent/Ping]

$ns connect $ping0 $ping4
$ns connect $ping1 $ping5

proc SendingPingPacket {} {
    global ns ping0 ping1
    set intervalTime 0.001
    set now [$ns now]
    $ns at [expr $now+$intervalTime] "$ping0 send"
    $ns at [expr $now+$intervalTime] "$ping1 send"
    $ns at [expr $now+$intervalTime] "SendingPacket"
}

Agent/Ping instproc recv {from rtt} {
    global seq
    $self instvar node_ 
    puts "The node [$node_id] received an ACK from the node $from with RTT $rtt"
}

$ping0 set class_ 1
$ping1 set class_ 2
$ping4 set class_ 3
$ping5 set class_ 5

$ns at 0.1 "SendingPingPacket"
$ns at 10.0 "finish"
$ns run