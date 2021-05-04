function add(a, b) {
  return a + b;
}

add(10, null);

const x: number | null = null;

const el = document.getElementById("status");

if (el) {
  el.textContent = "Ready";
}
el!.textContent = "Ready";
