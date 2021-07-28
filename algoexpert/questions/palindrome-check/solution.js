function isPalindrome(string) {
  let i = 0;
  let j = string.length - 1;

  while (i <= j) {
    const firstChar = string[i];
    const secondChar = string[j];

    if (firstChar !== secondChar) {
      return false;
    }

    i++;
    j--;
  }
  return true;
}
