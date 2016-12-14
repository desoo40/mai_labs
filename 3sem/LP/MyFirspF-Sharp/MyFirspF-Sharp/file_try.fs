open System
open System.Collections.Generic  
open System.IO  

module file_try =
    let lines = File.ReadAllLines("Sorokin Family.ged") |> Array.toList 
