%{
%}

%%
[0-9]{5}[- ][0-9]{7}[- ][0-9]{1}   	{printf("Valid String\n");}
.*					                {printf("Invalid String\n");}
%%