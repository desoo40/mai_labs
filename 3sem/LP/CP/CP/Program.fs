open System  
open System.Collections.Generic  
open System.IO  


let lines = File.ReadAllLines("Sorokin Family.ged") |> Array.toList

let IDlist = 
        lines
        |> List.filter (fun x -> x.StartsWith "0 @" ||
                                 x.StartsWith "1 HUSB" || 
                                 x.StartsWith "1 WIFE" || 
                                 x.StartsWith "1 CHIL" ||
                                 x.StartsWith "1 NAME")

let cleanList = 
    
    ignore IDlist

    for line in IDlist do
        if (line.StartsWith("0")) then
            ignore line.Substring()
        printfn "%A" line


//let memList =
//    
//    cleanList
//    |>List.append(fun x -> )
    
type memClass(id : int, name : string) =
    
    member this.ID = id
    member this.Name = name

type famClass(id : int, husb : memClass, wife : memClass, children : array<memClass>) =
    
    member this.ID = id
    member this.Husb = husb
    member this.Wife = wife
    member this.Children = children

    member this.Add = 
        this.Children
        |>Array.append

