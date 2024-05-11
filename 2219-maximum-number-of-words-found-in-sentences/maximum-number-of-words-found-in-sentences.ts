function mostWordsFound(sentences: string[]): number {
    let ans:number = 0;
    sentences.map((sentence)=>{
        let arr = sentence.split(' ');
        if(ans<arr.length) ans = arr.length;
    })
    return ans;
};