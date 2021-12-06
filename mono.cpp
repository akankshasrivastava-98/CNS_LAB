#include<bits/stdc++.h>
using namespace std ;
string uniquePlainText ;
string readPlainText(const char * name="plaintext.txt"){
string pt ;
ifstream fin;
fin.open(name) ;
fin>>pt ;
return pt ;
}
void permute(string a, int l, int r , vector<string>& ks)
{
if (l == r)
ks.push_back(a) ;
else
{
for (int i = l; i <= r; i++)
{
swap(a[l], a[i]);
permute(a, l+1, r , ks);
swap(a[l], a[i]);
}
}
}
vector<string> genKeySpace(string pt ){
set<char> charset ;
for(int i =0 ;i < pt.length() ; i++) charset.insert(pt[i]) ;
uniquePlainText
= string(charset.begin() , charset.end()) ;
vector<string> keyspace ;
permute(uniquePlainText , 0 , uniquePlainText.length()-1 , keyspace )
;
return keyspace ;
}
string encryptUsingKey(string uniq , string key){
string pt = readPlainText() ;
string ct = "" ;
for(int i =0 ;i < pt.length() ; i++){
char c = pt[i] ;
ct+=(key[uniq.find(c)]) ;
}
cout<<"Original text = \t " << pt << endl;
cout<< "Cipher text = \t\t " << ct <<endl;
return ct ;
}
void saveToFile(string data , string filename ="ciphertext.txt" ){
ofstream fout ;
fout.open(filename.c_str()) ;
fout<< data ;
fout.close() ;
}
void showFrequency(string pt , string ct){
map<char , char > mPlain ;
map<char , char > mCipher ;
for(int i =0 ;i < pt.length() ; i++){
mPlain[pt[i]]++ ;
mCipher[ct[i]]++ ;
}
cout<<"Frequency\t\tPlaintext Character\t\tCiphertext character"
<<endl;
cout<<"=========\t\t===================\t\t===================="
<<endl;
for(int i =0 ;i < pt.length() ; i++){
cout<< (float)mPlain[pt[i]]/pt.length() << "\t\t\t" << pt[i] <<
"\t\t\t" << ct[i] << endl ;
}
}
int main(void){
srand(time(0)) ;
string pt = readPlainText() ;
cout<<"Plain text = \t " << pt << endl;
vector<string> keyspace = genKeySpace(pt) ;
string key = keyspace[rand()%keyspace.size()] ;
cout<<"Unique chars = \t" << uniquePlainText <<endl;
for(int i=0; i < keyspace.size(); i++)
std::cout << keyspace.at(i) << ' ';
cout<<endl;
cout<<"Chosen key = \t" << key <<endl;
string ct = encryptUsingKey(uniquePlainText , key) ;
saveToFile(ct) ;
showFrequency(pt , ct) ;
}
