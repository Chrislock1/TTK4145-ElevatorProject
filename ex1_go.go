// Go 1.2
// go run helloworld_go.go

package main

import (
    . "fmt"
    "runtime"
    "time"
)

var i int = 0
func threadAdder() {
   for x := 0; x < 1000000; x++ {
       i++
   }
}
func threadSubtractor() {
   for y := 0; y < 1000000; y++ {
       i--
   }
}
func main() {

    runtime.GOMAXPROCS(runtime.NumCPU())    
                                           
    go threadAdder()
    go threadSubtractor()                     
    time.Sleep(100*time.Millisecond)
    Println(i)
}
