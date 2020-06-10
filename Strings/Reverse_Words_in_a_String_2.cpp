// Input:
// 2
// i.like.this.program.very.much
// pqr.mno
// Output:
// much.very.program.this.like.i
// mno.pqr

void reverseWords(char *s) {
    string ansString="";
    int i=0;
    while(s[i] != '\0'){
        string temp="";
        while(s[i] != '.' && s[i] != '\0'){
            temp += s[i];
            i++;
        }
        reverse(temp.begin(),temp.end());
        ansString += temp;
        if(s[i] == '\0')
            break;
        ansString += ".";
        i++;
    }
    reverse(ansString.begin(),ansString.end());
    cout<<ansString;
}
