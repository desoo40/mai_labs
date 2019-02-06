% Copyright

implement main
    open core

clauses
    programmer(X) :- study('MAI', X), know('Prolog', X).

		study('MAI', 'Mike').
		study('MAI', 'Masha').
		know('Prolog', 'Misha').
		know('C', 'Masha').

end implement main

goal
        ? - programmer(X), write(X).

